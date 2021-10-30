#include<bits/stdc++.h>
#include<mpi.h>
using namespace std;

typedef long long int LL;
typedef vector<vector<LL>> L2;
typedef vector<LL> L1;

#define MAX 10000
LL dist[MAX][MAX],result[MAX][MAX];
LL arr_row[MAX], arr_col[MAX];

void PrintDist(int id,LL N){
    if(id==0){
        for(int i = 0; i < N; i++){
    	    for(int j = 0; j < N; j++){        
    	        printf("%d ", dist[i][j]);
    	    }
    	    printf("\n");
    	}
    printf("\n");
    }
}

void CopyDist(LL N){
    for (int i = 0; i < N;++i){
        for (int j = 0; j < N;++j){
            dist[i][j] = result[i][j];
        }
    }
}

void initGLOBE(LL N){
	for (LL i = 0; i < N;++i){
		for (LL j = 0; j < N;++j){
			if(i==j){
				dist[i][j] = 0;
				result[i][j] = 0;
			}
			else{
				result[i][j] = 0;
				dist[i][j] = rand()*rand() % 100;
			}
		}
        arr_row[i] = 0;
        arr_col[i] = 0;
    }
}

void initLL(LL** dist, LL** result, LL N){
	for (LL i = 0; i < N;++i){
		for (LL j = 0; j < N;++j){
			if(i==j){
				dist[i][j] = 0;
				result[i][j] = 0;
			}
			else{
				result[i][j] = 0;
				dist[i][j] = rand() % 100;
			}
		}
	}
};

void Floyd_Simple(LL **dist, LL N){
	for (LL k = 0; k < N;++k){
		for (LL i = 0; i < N;++i){
			for (LL j = 0; j < N;++j){
				if(dist[i][j]>(dist[i][k]+dist[k][j])){
					dist[i][j]=dist[i][k]+dist[k][j];
					//path[i][j]=path[i][k];
				}
			}
		}
	}
};

double Floyd_Serial(L2 dist, L2 path, LL N){
	clock_t st, et;
	st = clock();
	for (LL k = 0; k < N;++k){
		for (LL i = 0; i < N;++i){
			for (LL j = 0; j < N;++j){
				if(dist[i][j]>(dist[i][k]+dist[k][j])){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[i][k];
				}
			}
		}
	}
	et = clock();
	return (double)(et - st)/CLOCKS_PER_SEC;
};

double Floyd_Parallel(LL** dist, LL** result, LL N){
	//计时
	clock_t st, et;
	st = clock();

	//初始化
	int process_num, id;
	MPI_Comm_size(MPI_COMM_WORLD, &process_num);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	int n = N / sqrt(process_num);//每个处理器的边长
	int process_num_per = N / n;//每一条边上的处理器数目
	MPI_Bcast(dist, N * N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);//初始广播：广播全局dist信息
	LL *arr_row = new LL[n];//用于存储第k次循环时所需的行和列
	LL *arr_col = new LL[n];

	//Floyd算法
	for (int k = 0; k < N;++k){
		
		/* 广播k行k列 */

		int blockid = k / n;
		int probef = blockid * process_num_per ; //第一个处理器前面的处理器数量
		int strow = probef;//第一个处理器的编号
		int stcol = blockid;
		//先列广播第k行
		for (int sendid = 0; sendid < process_num_per;++sendid,++strow){
			arr_row = &dist[k][sendid * n];
			for (int destid = strow - probef; destid<process_num; destid += process_num_per){
				if(id==strow && destid!=strow)//如果现在的核是发送核
					MPI_Send(arr_row, n, MPI_LONG_LONG, destid, 0, MPI_COMM_WORLD);
				if(id==destid)//如果现在的核是其中一个接受核
					MPI_Recv(arr_row, n, MPI_LONG_LONG, strow, 0, MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
			}	
		}
		//再行广播第k列
		for (int sendid = 0; sendid < process_num_per; ++sendid, stcol+=4){ //sendid描述temparray的位置
			for (int i = 0; i < n; ++i)//先把需要的列块装入arr_col
				arr_col[i] = dist[sendid * n + i][k];
			for (int destid = stcol - blockid, i = 0; i < process_num_per; ++destid, ++i){
				if(id==stcol && destid!=stcol)
					MPI_Send(arr_col, n, MPI_LONG_LONG, destid, 0, MPI_COMM_WORLD);
				if(id==destid)
					MPI_Recv(arr_col, n, MPI_LONG_LONG, stcol, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			}
		}

		/*每个处理器上的floyd算法*/
		int stline = floor(id / process_num_per) * n;
		for (int ii = 0, i = stline; ii < n; ++i){
			for (int jj = 0, j = (id - stline) * n; jj < n; ++j, ++jj){
				if(dist[i][j] > (arr_row[ii] + arr_col[jj]) ){
					dist[i][j] = (arr_row[ii] + arr_col[jj]);
					//path[i][j]=path[i][k];
				}
			}
		}
	}

	MPI_Reduce(dist, result, N*N, MPI_LONG_LONG, MPI_MIN, 0, MPI_COMM_WORLD);

	//打印结果
	for(int i = 0; i < N; i++){
    	for(int j = 0; j < N; j++){        
    	    printf("%d ", result[i][j]);
    	}
    	printf("\n");
    }
    printf("\n");

	//MPI_Finalize();
	et = clock();
	return (double)(et - st)/CLOCKS_PER_SEC;
};

int main(int argc, char *argv[]){
	//if(argc!=2)
	//	return -1;
	//LL N = atol(argv[1]);

    LL N = 4;
	initGLOBE(N);//全局变量初始化
	MPI_Init(&argc, &argv);//MPI初始化

	//计时
	clock_t st, et;
	st = clock();
	//初始化
	int process_num, id;    
	MPI_Comm_size(MPI_COMM_WORLD, &process_num);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
    PrintDist(id,N);
	int n = N / sqrt(process_num);//每个处理器的边长
	int process_num_per = N / n;//每一条边上的处理器数目
	MPI_Bcast(&dist, N * N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);//初始广播：广播全局dist信息
	MPI_Bcast(&arr_row, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
	MPI_Bcast(&arr_col, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);	
    //我觉得下面这三句不用也可以
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&process_num_per, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&N, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);



	//Floyd算法
	for (int k = 0; k < N;++k){
		/* 广播k行k列 */
		int blockid = k / n;//将dist视作棋盘划分时，k所在的行号
		int probef = blockid * process_num_per ; //第一个处理器前面的处理器数量
		int strow = probef;//第一个行处理器的编号
		int stcol = blockid;//第一个列处理器的编号
		//先列广播第k行
		for (int sendid = 0; sendid < process_num_per;++sendid,++strow){
			for (int i = 0; id==strow && i < n; ++i)//先把需要的行块装入arr_row
				arr_row[i] = dist[k][sendid * n + i];
                
			for (int destid = strow - probef; destid<process_num; destid += process_num_per){
				if(id==strow && destid!=strow)//如果现在的核是发送核
					MPI_Send(arr_row, n, MPI_LONG_LONG, destid, 0, MPI_COMM_WORLD);
				if(id==destid && destid!=strow)//如果现在的核是其中一个接受核
					MPI_Recv(arr_row, n, MPI_LONG_LONG, strow, 0, MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
			}	
		}
		//cout << k <<" row updated" << endl;
		//再行广播第k列
		for (int sendid = 0; sendid < process_num_per; ++sendid, stcol+=process_num_per){ //sendid描述temparray的位置
			for (int i = 0; id==stcol && i < n; ++i)//先把需要的列块装入arr_col
				arr_col[i] = dist[sendid * n + i][k];

			for (int destid = stcol - blockid, i = 0; i < process_num_per; ++destid, ++i){
				if(id==stcol && destid!=stcol)
					MPI_Send(arr_col, n, MPI_LONG_LONG, destid, 0, MPI_COMM_WORLD);
				if(id==destid && destid!=stcol)
					MPI_Recv(arr_col, n, MPI_LONG_LONG, stcol, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			}
		}
		cout << k << " col updated" << endl;

		/*每个处理器上的floyd算法*/
		int stline = floor(id / process_num_per) * n;
		for (int ii = 0, i = stline; ii < n; ++i,++ii){
			for (int jj = 0, j = (id - stline) * n; jj < n; ++j, ++jj){
				cout << "dist=" << dist[i][j] << " arr= " << (arr_row[jj] + arr_col[ii]) << endl;
				if(dist[i][j] > (arr_row[jj] + arr_col[ii]) ){
					dist[i][j] = (arr_row[jj] + arr_col[ii]);
				}
			}
		}
		cout << k<<" floyd updated" << endl;
        // if(id==0){
        //     MPI_Reduce(dist, result, N*N, MPI_LONG_LONG, MPI_MIN, 0, MPI_COMM_WORLD);
        //     CopyDist(N);     
        //     MPI_Bcast(&dist, N * N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);//初始广播：广播全局dist信息       
        // }
    }

	MPI_Reduce(dist, result, N*N, MPI_LONG_LONG, MPI_MIN, 0, MPI_COMM_WORLD);

	//打印结果
    PrintDist(id,N);
	MPI_Finalize();
	et = clock();
	double time = (double)(et - st)/CLOCKS_PER_SEC;

	//MPI_Finalize();
    if(id==0)
	    cout << "time: " << time << endl;
	//L2 dist(N, L1(N)), path(N, L1(N)); //使用容器vector时的初始化
	//double time = Floyd_Serial(dist, path, N);
	//cout << time/sqrt(N)<< endl;
	return time;
}
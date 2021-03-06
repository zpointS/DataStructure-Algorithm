#include "mpi.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef vector<vector<LL>> L2;
typedef vector<LL> L1;

#define MAX 10000
LL dist[MAX][MAX], result[MAX][MAX];
LL arr_row[MAX], arr_col[MAX];


void Initialize(LL N){
    for (int i = 0; i < N;++i){
	for (int j = 0; j < N;++j){
		if(i==j)
			dist[i][i] = 0;
		else
            dist[i][j] = rand() % 100;
		}
	}
}

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

void Floyd_Simple(LL **dist, LL N){
	for (LL k = 0; k < N;++k){
		for (LL i = 0; i < N;++i){
			for (LL j = 0; j < N;++j){
				if(dist[i][j]>(dist[i][k]+dist[k][j])){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
};

double Floyd_Serial(LL N){
	clock_t st, et;
	st = clock();
	for (LL k = 0; k < N;++k){
		for (LL i = 0; i < N;++i){
			for (LL j = 0; j < N;++j){
				if(dist[i][j]>(dist[i][k]+dist[k][j])){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	et = clock();
	return (double)(et - st)/CLOCKS_PER_SEC;
};

double Floyd_Parallelism_ROW(LL N,int argc,char *argv[]){
    /*初始化*/
    clock_t st, et;
    MPI_Init(&argc,&argv);
    int process_num, id;//process_num为进程数,id为进程号
    MPI_Comm_size(MPI_COMM_WORLD, &process_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    LL n = N / process_num; //n是每个处理器的边长
    MPI_Bcast(dist, MAX*MAX, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&N, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
    //PrintDist(id, N);//打印初始dist矩阵
    

    /*按行分块的Floyd并行算法*/
    if(id==0) st = clock();
    for (int k=0;k<N;++k){
        //用于确定需要进行广播的进程编号
        int sentee = floor(k / n);
        for (int destid = 0; destid < process_num;++destid){
            if (id == sentee && destid!=sentee)
                MPI_Send(dist[k], N, MPI_INT, destid, 0, MPI_COMM_WORLD);
            else if( id==destid && destid!=sentee)
                MPI_Recv(dist[k], N, MPI_INT, sentee, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        }
        //在子进程中进行串行floyd算法
        for (int i=n*(id);i<n*(id+1);++i){  
            for (int j=0;j<N;++j){
                if (dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k] + dist[k][j];
                }
            }
        }
    }
    /*合并所有子块的内容*/
    MPI_Reduce(dist, result, MAX*MAX, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    if(id==0) et = clock();


    //PrintDist(id, N);
    MPI_Finalize();//关闭MPI
    if(id==0) return (double)(et - st) / CLOCKS_PER_SEC;
};

double Floyd_Parallelism_BLOCK(LL N, int argc, char *argv[]){
	/*初始化*/
	clock_t st, et;    
    MPI_Init(&argc,&argv);
	int process_num, id;    
	MPI_Comm_size(MPI_COMM_WORLD, &process_num);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	int n = N / sqrt(process_num);//每个处理器的边长
	int process_num_per = N / n;//每一条边上的处理器数目
	MPI_Bcast(&dist, N * N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);//初始广播：广播全局dist信息
	MPI_Bcast(&arr_row, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
	MPI_Bcast(&arr_col, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);	
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&process_num_per, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&N, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
    //PrintDist(id,N);

	/*Floyd算法*/
    st = clock();
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

		/*每个处理器上的floyd算法*/

		int stline = floor(id / process_num_per) * n;
		for (int ii = 0, i = stline; ii < n; ++i,++ii){
			for (int jj = 0, j = (id - stline) * n; jj < n; ++j, ++jj){
				if(dist[i][j] > (arr_row[jj] + arr_col[ii]) ){
					dist[i][j] = (arr_row[jj] + arr_col[ii]);
				}
			}
		}
    }
    MPI_Reduce(dist, result, N*N, MPI_LONG_LONG, MPI_MIN, 0, MPI_COMM_WORLD);
    et = clock();

    return (double)(et - st) / CLOCKS_PER_SEC;
};


int main(int argc, char *argv[]){
    if(argc!=2)
        return -1;
    LL N = atol(argv[1]);

    double timeP, timeS;
    Initialize(N);

    timeP = Floyd_Parallelism_ROW(N, argc, argv);
    timeS = Floyd_Serial(N);

    cout << setiosflags(ios::fixed) << setprecision(10) << "timeP: " << timeP << " timeS: " << timeS << endl;
    return min(timeS, timeP);
}


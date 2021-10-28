#include "mpi.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef vector<vector<LL>> L2;
typedef vector<LL> L1;

#define MAX 11000
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

    clock_t st, et;
    MPI_Init(&argc,&argv);
    int process_num, id;
    MPI_Comm_size(MPI_COMM_WORLD, &process_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    LL n = N / process_num; 
    MPI_Bcast(dist, MAX*MAX, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&N, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
    //PrintDist(id, N);
    

    if(id==0) st = clock();
    for (int k=0;k<N;++k){

        int sentee = floor(k / n);
        for (int destid = 0; destid < process_num;++destid){
            if (id == sentee && destid!=sentee)
                MPI_Send(dist[k], N, MPI_INT, destid, 0, MPI_COMM_WORLD);
            else if( id==destid && destid!=sentee)
                MPI_Recv(dist[k], N, MPI_INT, sentee, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        }

        for (int i=n*(id);i<n*(id+1);++i){  
            for (int j=0;j<N;++j){
                if (dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k] + dist[k][j];
                }
            }
        }
    }

    MPI_Reduce(dist, result, MAX*MAX, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    if(id==0) et = clock();


    //PrintDist(id, N);
    MPI_Finalize();
    if(id==0) return (double)(et - st) / CLOCKS_PER_SEC;
};

double Floyd_Parallelism_BLOCK(LL N, int argc, char *argv[]){
	
	clock_t st, et;    
    MPI_Init(&argc,&argv);
	int process_num, id;    
	MPI_Comm_size(MPI_COMM_WORLD, &process_num);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	int n = N / sqrt(process_num);
	int process_num_per = N / n;
	MPI_Bcast(&dist, N * N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
	MPI_Bcast(&arr_row, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
	MPI_Bcast(&arr_col, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);	
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&process_num_per, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&N, N, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
    //PrintDist(id,N);


    st = clock();
    for (int k = 0; k < N;++k){

		int blockid = k / n;
		int probef = blockid * process_num_per ; 
		int strow = probef;
		int stcol = blockid;

		for (int sendid = 0; sendid < process_num_per;++sendid,++strow){
			for (int i = 0; id==strow && i < n; ++i)
				arr_row[i] = dist[k][sendid * n + i];
                
			for (int destid = strow - probef; destid<process_num; destid += process_num_per){
				if(id==strow && destid!=strow)
					MPI_Send(arr_row, n, MPI_LONG_LONG, destid, 0, MPI_COMM_WORLD);
				if(id==destid && destid!=strow)
					MPI_Recv(arr_row, n, MPI_LONG_LONG, strow, 0, MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
			}	
		}

		for (int sendid = 0; sendid < process_num_per; ++sendid, stcol+=process_num_per){ 
			for (int i = 0; id==stcol && i < n; ++i)
				arr_col[i] = dist[sendid * n + i][k];

			for (int destid = stcol - blockid, i = 0; i < process_num_per; ++destid, ++i){
				if(id==stcol && destid!=stcol)
					MPI_Send(arr_col, n, MPI_LONG_LONG, destid, 0, MPI_COMM_WORLD);
				if(id==destid && destid!=stcol)
					MPI_Recv(arr_col, n, MPI_LONG_LONG, stcol, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			}
		}

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
    timeP = Floyd_Parallelism_BLOCK(N, argc, argv);
    //timeS = Floyd_Serial(N);
    cout << setiosflags(ios::fixed) << setprecision(10) << "timeP: " << timeP << endl;

    return timeP;
}

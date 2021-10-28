#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "stdint.h"
#include "mpi.h"
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
#define NOT_CONNECTED -1

int distances[MAX][MAX];
int result[MAX][MAX];
int nodesCount;//number of nodes

//initialize all distances to 
void Initialize(){
    // memset(distances, NOT_CONNECTED , sizeof(distances));
    // memset(result, NOT_CONNECTED , sizeof(result));
    // for (int i=0;i<MAX;++i)
    //     distances[i][i]=0;
    for (int i = 1; i <= nodesCount;++i){
	for (int j = 1; j <= nodesCount;++j){
		if(i==j){
			distances[i][i] = 0;
			// path[i][i] = 0;
		}
		distances[i][j] = rand() % 100;
		// path[i][j] = rand() % 100;
		}
	}

    // for(int i = 1; i <= nodesCount; i++)
    //     {
    //         for(int j = 1; j <= nodesCount; j++)
    //         {        
    //             printf("%d ", distances[i][j]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
}

int cmp ( const void *a , const void *b ){
    return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[]){
    nodesCount = 16;
    Initialize();
    //get the nodes count
    // scanf("%d", &nodesCount);

    //edges count
    int m;
    // scanf("%d", &m);

    // while(m--){
    //     //nodes - let the indexation begin from 1
    //     int a, b;
    //     //edge weight
    //     int c;
    //     scanf("%d-%d-%d", &a, &c, &b);
    //     distances[a][b]=c;
    // }

    int size, rank;//size为进程数,rank为进程号

    MPI_Init(&argc,&argv);

    MPI_Datatype rtype;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    //从此之后，剩下的所有的代码都是并行地在所有进程上同时跑的  ·

    int slice = (nodesCount)/size;//slice是每个处理器的边长

    /*广播初始数据
    一个广播发生的时候，一个进程会把同样一份数据传递给一个 communicator 里的所有其他进程。
    根节点调用 MPI_Bcast 函数的时候，data 变量里的值会被发送到其他的节点上。
    当其他的节点调用 MPI_Bcast 的时候，data 变量会被赋值成从根节点接受到的数据。*/
    MPI_Bcast(distances, MAX*MAX, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&nodesCount, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&slice, 1, MPI_INT, 0, MPI_COMM_WORLD);

    //Floyd-Warshall
    int sent=1;

    for (int k=1;k<=nodesCount;++k){
        //用于确定需要进行广播的进程编号
        int th = 1;

        for(; th <= size; th++)//size是进程数
        {
            if(1+slice*(th-1) <= k && k <= slice*th)
                sent = th;
        }
        if(1+slice*(th-1) <= k && k <= nodesCount)
            sent = size;

        //把第k行的数据进行广播
        MPI_Bcast(&distances[k], nodesCount+1, MPI_INT, sent-1, MPI_COMM_WORLD);

        //在子进程中进行串行floyd算法
        if(rank != size-1){
            for (int i=1+slice*(rank);i<=slice*(rank+1);++i){  
                if (distances[i][k]!=NOT_CONNECTED){
                    for (int j=1;j<=nodesCount;++j){
                        if (distances[k][j]!=NOT_CONNECTED && (distances[i][j]==NOT_CONNECTED 
                            || distances[i][k]+distances[k][j]<distances[i][j])){
                            distances[i][j]=distances[i][k] + distances[k][j];
                        }
                    }
                }
            }
        }

        else{
            for (int i=1+slice*rank;i<=nodesCount;++i){
                if (distances[i][k]!=NOT_CONNECTED){
                    for (int j=1;j<=nodesCount;++j){
                        if (distances[k][j]!=NOT_CONNECTED && (distances[i][j]==NOT_CONNECTED 
                            || distances[i][k]+distances[k][j]<distances[i][j])){
                            distances[i][j]=distances[i][k]+distances[k][j];
                        }
                    }
                }
            }
        }
    }


    for (int k=1;k<=nodesCount;++k){

        int th = 1;
        for(; th <= size; th++)
        {
            if(1+slice*(th-1) <= k && k <= slice*th)
                sent = th;
        }
        if(1+slice*(th-1) <= k && k <= nodesCount )
            sent = size;

        MPI_Bcast(&distances[k], nodesCount+1, MPI_INT, sent-1, MPI_COMM_WORLD);
    }

    //因为每个处理机只处理了自己的那一块数据使之为最优。
    //每个进程发送容量为 count 的数组 send_data，root 进程收到后进行 op 操作，存放在容量也为 count 的数组 recv_data 中。
    MPI_Reduce(distances, result, MAX*MAX, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    if(rank==0)
    {
        for(int i = 1; i <= nodesCount; i++)
        {
            for(int j = 1; j <= nodesCount; j++)
            {        
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    /* Shut down MPI */
    MPI_Finalize();

    return 0;
}


#include <iostream> 
#include <mpi.h> 
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) 
{ 
	// vector<int> num = {55,66,77};
    int num[] = {55, 66, 77};
    cout << num[1]<<" "<<num[2] << endl;

    MPI_Init(&argc, &argv); 

	int RankID; 
	MPI_Comm_rank(MPI_COMM_WORLD, &RankID);
    MPI_Bcast(num, 3, MPI_INT, 0, MPI_COMM_WORLD);
    cout << "first broad "<< RankID <<" "<<num[0]<<" "<<num[1]<<" "<<num[2] << endl;

    num[RankID] = RankID;
    if(RankID==1)cout << "first change "<< RankID <<" "<<num[0]<<" "<<num[1]<<" "<<num[2] << endl;
    if(RankID==2)cout << "first change "<< RankID <<" "<<num[0]<<" "<<num[1]<<" "<<num[2] << endl;
    MPI_Bcast(num+2, 1, MPI_INT, 2, MPI_COMM_WORLD); 
    if(RankID==1)cout << "second broad "<< RankID <<" "<<num[0]<<" "<<num[1]<<" "<<num[2] << endl;
    if(RankID==2)cout << "second broad "<< RankID <<" "<<num[0]<<" "<<num[1]<<" "<<num[2] << endl;
    MPI_Bcast(num+1, 1, MPI_INT, 1, MPI_COMM_WORLD);
    if(RankID==1)cout << "third broad "<< RankID <<" "<<num[0]<<" "<<num[1]<<" "<<num[2] << endl;
    if(RankID==2)cout << "third broad "<< RankID <<" "<<num[0]<<" "<<num[1]<<" "<<num[2] << endl;
    // if (1 == RankID) 
	// {
    //     num[1] = 100;
    //     cout << "p1 change num to "<< num[1]<<" "<<num[2] << endl; ...
    //     MPI_Bcast(num, 3, MPI_INT, 1, MPI_COMM_WORLD); 
    //     cout << "p1 broad num to "<< num[1]<<" "<<num[2] << endl;
	// } 
    // else if (2 == RankID) 
	// { 
	// 	num[2] = 200;
    //     cout << "p2 change num to "<< num[1]<<" "<<num[2] << endl;
    //     MPI_Bcast(num, 3, MPI_INT, 2, MPI_COMM_WORLD);
    //     cout << "p2 broad num to "<< num[1]<<" "<<num[2] << endl;
	// }

    cout << "finally: "<<RankID<<" "<<num[0]<<" "<<num[1]<<" "<<num[2] << endl;
    MPI_Finalize(); 
	return 0; 
} 

// MPI_Reduce(distances, result, MAX*MAX, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
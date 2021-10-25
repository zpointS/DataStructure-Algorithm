#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef vector<vector<LL>> L2;
typedef vector<LL> L1;

void init(L2 dist, L2 path, LL N){
	for (LL i = 0; i < N;++i){
		for (LL j = 0; j < N;++j){
			if(i==j){
				dist[i][i] = 0;
				path[i][i] = 0;
			}
			dist[i][j] = rand() % 100;
			path[i][j] = rand() % 100;
		}
	}
	return;
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

double Floyd_Parallel(L2 dist, L2 path, LL N);

int main(int argc, char *argv[]){
	if(argc!=2)
		return -1;
	LL N = atol(argv[1]);
	L2 dist(N, L1(N)), path(N, L1(N));
	init(dist, path, N);
	double time = Floyd_Serial(dist, path, N);
	cout << time/sqrt(N)<< endl;
	return time/sqrt(N);
}
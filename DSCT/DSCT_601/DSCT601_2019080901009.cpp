#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;

LL Solve(vector<LL> w, vector<LL> v, LL N, LL W){
	vector<LL> V(W+1, 0);
	for (LL item = 1; item <= N; item++){
		for (LL weight = W; weight >= w[item];weight--){
			V[weight] = max(V[weight], V[weight - w[item]] + v[item]);
		}
	}
	return V[W];
};


int main(int argc, char *argv[]){
	if(argc!=2)
		return -1;

	ifstream file;
	file.open(argv[1]);
	LL N, W, i=1;
	file >> N >> W;
	vector<LL> v(N + 1, 0);
	vector<LL> w(N + 1, 0);

	while(!file.eof()){
		file >> w[i] >> v[i];
		i++;
	}
	file.close();

	LL V = Solve(w, v, N, W);
	printf("%lld",V);
	return 0;
}
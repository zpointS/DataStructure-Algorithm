#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;

LL Combination(LL n, LL m){
	if(n==m || m==0)
		return 1;
	return Combination(n, m - 1) * (n - m + 1) / m;
};

int main(int argc, char *argv[]){
	if(argc!=2)
		return -1;
	LL n = atol(argv[1]);
	cout << Combination(2 * n, n) / (n + 1) << endl;
	return 0;
}
#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;

//素数筛法求素数
vector<LL> prime(LL upper_bound){
	vector<LL> p(upper_bound + 1, 0); //0表示是素数，1表示是合数
	for (LL i = 2; i <= upper_bound;++i){//已剪枝
		if(!p[i]){//如果当前数是素数，那么他的倍数将全部都是合数
			LL times = upper_bound / i;
			for (LL j = i; j <= times;++j){//已剪枝
				p[i * j] = 1;
			}
		}
	}
	return p;
}


vector<LL> Solve(vector<LL> p, LL N, LL upper_bound){
	vector<LL> ans;
	for (LL factor = 2; factor <= upper_bound;++factor){
		if(!p[factor]){
			while(!(N%factor)){
				ans.push_back(factor);
				N /= factor;
			}
		}
	}
	if(N>1){//最多有一个大于sqrt(N)的素因子
		ans.push_back(N);
	}

	return ans;
};

int main(int argc, char *argv[]){
	if(argc!=2)
		return -1;

	LL N = atol(argv[1]);
	LL upper_bound = (LL)sqrt(N);
	vector<LL> p = prime(upper_bound);
	vector<LL> ans = Solve(p, N, upper_bound);

	LL len = ans.size();
	for (LL i = 1; i < len;++i){
		printf("%lld*", ans[i - 1]);
	}
	printf("%lld", ans.back());

	return 0;
}
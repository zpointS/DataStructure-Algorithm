#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;

LL maxdepth(LL n){
	LL a=1, b=2, c=0;
	for (int depth = 1;;++depth){
		if(n>=a && n<b)
			return depth;
		c = a + b;
		a = b;
		b = c;
	}
};


LL Solve(LL n, LL depth){
	vector<vector<LL>> avl(n + 1, vector<LL>(depth + 1));
	LL result = 0;
	avl[0][0] = 1;
	avl[0][1] = 0;
	avl[1][0] = 0;
	avl[1][1] = 1;

	for (LL i = 2; i <= n;++i){//动态规划算出每一个节点数的每一个可能深度的形态数
		for (LL j = 2; j <= maxdepth(i);++j){//对节点数为i的AVL树算出深度为j的每一个情况的形态数
			for (LL k = 0; k < i;++k){//具体计算方案
				//左右子树深度相同，均为j-1
				avl[i][j] += avl[i - 1 - k][j - 1] * avl[k][j - 1];
				//左右子树深度相差1
				avl[i][j] += avl[i - 1 - k][j - 2] * avl[k][j - 1] * 2;
			}
		}
	}

	for (LL ii = 1; ii <= depth;++ii)
		result += avl[n][ii];

	return result;
};

int main(int argc, char *argv[]){
	if(argc!=2)
		return -1;
	LL n = atol(argv[1]);
	LL depth = maxdepth(n);
	cout << Solve(n, depth) << endl;
	return 0;
}
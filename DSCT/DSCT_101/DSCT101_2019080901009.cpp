#include<bits/stdc++.h>
using namespace std;

long long solve(long long num){
	if (num == 0)  
		return 1; 
	if (num == -1)  
		return 0; 
	
	long long top;
	long long i = 0;
	long long tmp = num;

	double log2 = log(2);//用于换底公式；注意log表示的实际上是ln

	top = log(num) / log2;

	while (tmp > 0) {//前面的1清零直到num的二进制中的最靠左的0出现 
		tmp -= (1<<(top - i));
		i++;
	}

	if(top>=i)
		tmp = (1<<(top - i));//第一个0的地方加一 
	else  
		tmp = -1;//如果num的二进制表示全是1，那就不存在这种情况 

	return solve(num - (1 << top)) + solve(tmp);//使用最大的硬币与否
}

int main(int argc, char *argv[]) {
	long long num = atol(argv[1]);
	cout << solve(num) << endl;

	return 0;
}

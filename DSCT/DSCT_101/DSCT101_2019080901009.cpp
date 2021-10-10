#include<bits/stdc++.h>
using namespace std;

long long solve(long long num){
	long long k;
	long long i = 0;
	long long m = num;
	long long p;

	double log2 = log(2);//用于换底公式；注意log表示的实际上是ln
	
	k = log(num) / log2;//二进制表示的最高位 

	while (m > 0) {
		p = log(m) / log2;
		if (p == k-i) {
			m = m - (1<<(k - i));
			i++;
		}
		else  
			break; 
	}//前面的1清零直到左数第一个0出现 

	if(k-i>=0)
		m += (1<<(k - i));//第一个0的地方加一 
	else  
		m = -1;//如果全是1那就不存在这种情况 

	if (num == 0)  
		return 1; 
	if (num == -1)  
		return 0; 

	return solve(num - (1 << k)) + solve(m);//第一种是使用最大的硬币的方案数，第二个是不用最大硬币的方案数 
}

int main() {
	//int argc, char *argv[]
    //if(argc != 2)
	//	return -1;
	//long long num = atol(argv[1]);
	//long long num;
	//cin >> num;
	long long result = solve(31);
	//cout << result << endl;
	printf("%lld", result);

	//system("pause");
	return 0;
}

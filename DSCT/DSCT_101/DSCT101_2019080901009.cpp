#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;

long long solve(long long num){
	if (num == 0)  
		return 1; 
	if (num == -1)  
		return 0; 

	double log2 = log(2);//用于换底公式；注意log表示的实际上是ln
	long long num2pos = log(num) / log2;//二进制表示的最高位	
	long long cur2pos;//减去最高位后的num的最高位的位置
	long long i = 0;
	long long tmpnum = num;

	while (tmpnum > 0) {
		cur2pos = log(tmpnum) / log2;
		if (cur2pos+i == num2pos) {
			tmpnum -= (1<<(num2pos-i));
			i++;
		}
		else  
			break; 
	}//前面的1清零直到左数第一个0出现 

	if(num2pos>=i)
		tmpnum += (1<<(num2pos - i));//第一个0的地方加一 
	else  
		tmpnum = -1;//如果全是1那就不存在这种情况 

	return solve(num - (1 << num2pos)) + solve(tmpnum);//第一种是使用最大的硬币的方案数，第二个是不用最大硬币的方案数 
}

int main(int argc, char *argv[]) {
    if(argc != 2)
		return -1;
		
	long long num = atol(argv[1]);
	long long result = solve(num);
	cout << result << endl;

	return 0;
}

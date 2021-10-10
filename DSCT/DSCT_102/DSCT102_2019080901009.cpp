#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
	if(argc==1)
		return -1;

	long long int piece_num = argc - 1; //参数个数，要减去1，这个1表示程序本身

	long long int* piece_len = new long long int[piece_num];
	for (int i = 0; i < piece_num; i++)
	{
		piece_len[i] = (long long int)atoi(argv[i+1]);
	}

	sort(piece_len,piece_len+piece_num);//从小到大排序

	long long spending=piece_len[0]*(piece_num-1);

	for(int i=1;i<piece_num;i++)
		spending += piece_len[i]*(piece_num-i);

	cout << spending <<endl;

	return 0;
}
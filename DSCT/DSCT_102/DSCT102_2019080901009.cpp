#include <bits/stdc++.h>
#include <queue>
#pragma GCC optimize(3)

using namespace std;

unsigned long long solve(unsigned long long* pieces, unsigned long long pieces_num) {
	unsigned long long sum = 0;
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>>q;

	for (long long i = 0; i < pieces_num; i++) 
		q.push(pieces[i]);
 
    while(true){
		if(q.size() > 1){
         	long long len1, len2;

         	len1 = q.top(); 
		 	q.pop();        
         	len2 = q.top(); 
		 	q.pop();        
         	sum += (len1 + len2);
         	q.push(len1 + len2);     
		}
		else 
			break;
	}

	return sum;
}

int main(int argc, char *argv[]){
	if(argc == 1){
		return -1;
	}

	int pieces_num = argc - 1;
	unsigned long long* pieces = new unsigned long long[pieces_num];
	for (int i = 1; i < argc; i++)
	{
		pieces[i - 1] = (unsigned int)atoi(argv[i]);
	}
	
	cout << solve(pieces, pieces_num) << endl;
	
	delete[] pieces;
	return 0;
}
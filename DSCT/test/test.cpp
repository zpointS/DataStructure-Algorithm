#include<bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
        if(ratings.size()<2) return ratings.size();
        vector<int> candies(ratings.size(), 1);
        int sum = 0,i = 0;

        for(int i=1;i<ratings.size();++i){
            if(ratings[i]>ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }

        for(int i = ratings.size()-1; i>0; --i){
            if(ratings[i]<ratings[i-1]){
                candies[i-1] = max(candies[i-1],candies[i]+1);
            }
        }
        return accumulate(candies.begin(),candies.end(),0);
    }

int main(){
    vector<int> ratings = {1,2,87,87,87,2,1};
    int sum = candy(ratings);

    int a;
    return 0;
}
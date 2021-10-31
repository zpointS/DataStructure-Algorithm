#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 60;
    int col = 10;
    int row = num/col;
    int randnum;

    ofstream File;
    File.open("n.txt");
    // for (int i = 0; i < row;++i){
    //     for (int j = 0; j < col;++j){
    //         randnum = rand()*rand() % 1000;
    //         File << randnum << ' ';
    //     }
    //     File << '\n';
    // }
    int bound = 40;
    while(bound){
        File << bound << '\n';
        bound--;
    }

    return 0;
}
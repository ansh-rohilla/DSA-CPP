#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;

int diagonalSum(int matrix[][4] , int n){
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += matrix[i][i];
        if(i != n-i-1){
            sum += matrix[i][n-i-1];
        }
    }
    return sum;
}
int main(){
    vector<vector<int>> mat = {{1,2,3} , {4,5,6,10,11} , {7,8,9}};

    for(int i = 0 ; i<mat.size() ; i++){
        for(int j = 0 ; j<mat[i].size() ; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
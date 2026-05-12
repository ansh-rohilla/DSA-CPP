#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

void linearSearch(int matrix[][3] , int rows , int columns , int target){
    for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j<columns ; j++){
            if(target == matrix[i][j]){
                cout<<"Target found at the cell "<<"row="<<i<<" column="<<j;
            }
        }
    }
         cout<<"Target not found in the matrix!!";
}

int getMaxSum(int matrix[][3] , int rows , int columns) {
    int maxRowSum = INT_MIN;

    for(int i = 0 ; i<rows ; i++){
        int rowSumI = 0;
        for(int j = 0 ; j<columns ; j++){
            rowSumI += matrix[i][j];
        }

        maxRowSum = max(maxRowSum , rowSumI);
    }

    return maxRowSum;
}
int main(){
    int matrix[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}};
    int rows = 3;
    int columns = 3;
    // int target = 18;
    // input
    // for(int i = 0 ; i<rows ; i++){
    //     for(int j = 0 ; j<columns ; j++){
    //         cin>>matrix[i][j];
    //     }
    // }
    // linearSearch(matrix , rows , columns , target);
    cout<<getMaxSum(matrix , rows , columns);
    return 0;
}
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root , int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insert(root->left , val);
    } else {
        root->right = insert(root->right , val);
    }

    return root;
}

void inorder(Node*root , vector<int> &arr){
    if(root == NULL){
        return;
    }

    inorder(root->left , arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

Node* buildBSTFromSorted(vector<int> arr , int st ,int end){
    if(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* root = new Node(arr[mid]);
    root->left = buildBSTFromSorted(arr , st , mid-1);
    root->right = buildBSTFromSorted(arr , mid+1 , end);

    return root;
}
Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int val : arr){
        root = insert(root , val);
    }

    return root;
}

class Info {
public:
    int min , max , sz;

    Info(int mi , int ma , int size){
        min = mi;
        max = ma;
        sz = size;
    }

};

Info helper(Node* root) {
    if(root == NULL){
        return Info(INT_MAX , INT_MIN , 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data < right.min) {
        int currMin = min(root->data , left.min);
        int currMax = max(root->data , right.max);
        int currSz = left.sz + right.sz + 1;

        return Info(currMin , currMax , currSz);
    }

    return Info(INT_MIN , INT_MAX , max(left.sz , right.sz));

}

int largestBSTinBT(Node* root) {
    Info info = helper(root);
    return info.sz;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(50);

    cout<<largestBSTinBT(root)<<endl;
    return 0;
}

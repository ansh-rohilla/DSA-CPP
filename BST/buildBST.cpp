#include<iostream>
#include<vector>
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

void inOrder(Node*root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int val : arr){
        root = insert(root , val);
    }

    return root;
}

int main(){
    vector<int> arr = {3,2,1,5,6,4};

    Node* root = buildBST(arr);
    inOrder(root);
    cout<<endl;
    return 0;
}

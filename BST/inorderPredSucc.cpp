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



int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(50);

    return 0;
}

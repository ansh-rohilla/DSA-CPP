#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
};

void preOrder(Node* root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }
        cout<<curr->data<<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

void topView(Node* root){
    queue<pair<Node* ,int>>q; // pair of (node , HD)
    map<int , int> m; // ordered map as the data should be ordered <HD , node Val>
    q.push({root , 0});

    while(q.size() > 0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()){
            m[currHD] = curr->data;
        }
        if(curr->left != NULL){
            q.push({curr->left , currHD - 1});
        }
        if(curr->right != NULL){
            q.push({curr->right , currHD + 1});
        }
    }
    for (auto it : m){
        cout<<it.second <<" ";
    }
}


int main(){
    vector<int> preorder = {1, 2 ,-1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    topView(root);
    return 0;
}
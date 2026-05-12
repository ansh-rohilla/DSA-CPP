#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph {
    int V; // no of vertices
    list<int> *l; // dynamic array of lists 

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }
    void addEdge(int u , int v){
        l[u].push_back(v); // only directed graph
    }

    void dfs(int curr , vector<bool> &vis , stack<int> &s){
        vis[curr] = true;

        for(int nbr : l[curr]){
            if(!vis[nbr]){
                dfs(nbr,vis,s);
            }
        }
        // at this point , all nbrs are visited
        s.push(curr);
    }
    void topologicalSort(){
        vector<bool> vis(V,false);
        stack<int> s;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,s);
            }
        }

        // print stack
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }
    
};
int main() {

    Graph g(6);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,3);

    g.topologicalSort();
    return 0;
}
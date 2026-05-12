#include<iostream>
#include<vector>
#include<list>
#include<queue>

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
        l[u].push_back(v);
        l[v].push_back(u); // undirected graph

    }

    //BFS Traversal
    void bfs(){
        queue<int> Q;
        vector<bool> vis(V,false);

        Q.push(0);
        vis[0]=true;

        while(Q.size() > 0){
            int u = Q.front();
            Q.pop();

            cout<<u<<" ";
            for(int v : l[u]){
                if(!vis[v]){
                    Q.push(v);
                    vis[v]=true;
                }
            }
        }
        cout<<endl;
    }

    // DFS Traversal
    void dfsHelper(int u , vector<bool> &vis){
        // visit node
        cout<<u<<" ";
        vis[u]=true;

        // go to all unvisited neighbours
        for(int v : l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        int src = 0;
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i,vis);
            }
        }
        cout<<endl;
    }
};
int main() {

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    cout<<"BFS Traversal: ";
    g.bfs();
    cout<<"DFS Traversal: ";
    g.dfs();
    return 0;
}
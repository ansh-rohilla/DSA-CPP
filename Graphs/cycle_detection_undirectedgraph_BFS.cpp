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
     
    bool isCycleUndirBFS(int src , vector<bool> &vis){
        queue<pair<int,int>> q;
        vis[src] = true;
        q.push({src,-1}); // node , parent

        while(!q.empty()){
            int node = q.front().first;
            int parent = q .front().second;
            q.pop();

            list<int> neighbours = l[node];
            for(int nbr : neighbours){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push({nbr,node});
                }
                else if(nbr != parent){
                    // visited and not parent
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(){
        vector<bool> vis(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleUndirBFS(i,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    
};
int main() {

    Graph g(5);
    g.addEdge(0,1);
    // g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    cout << g.isCycle() << endl;
    return 0;
}
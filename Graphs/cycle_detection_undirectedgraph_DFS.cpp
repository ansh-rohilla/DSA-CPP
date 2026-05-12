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

    bool isCycleUndirectedDFS(int src , int par , vector<bool> &vis){ // dfs algorithm
        vis[src]=true;
        list<int> neighbours = l[src];

        for(int nbr : neighbours){
            if(!vis[nbr]){
                if (isCycleUndirectedDFS(nbr,src,vis)){
                    return true;
                }
            } else if(nbr != par){
                return true;
            } 
        }
        return false;
    }
    bool isCycle(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleUndirectedDFS(i,-1,vis)){
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
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    cout<<"Cycle Present or Not: "<<g.isCycle()<<endl;
    return 0;
}
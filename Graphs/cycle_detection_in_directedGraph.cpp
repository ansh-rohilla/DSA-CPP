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
        l[u].push_back(v); // directed graph
    }

    //cycle detection
    bool isCycleDirDFS(int curr , vector<bool> &vis , vector<bool> &recPath){
        vis[curr] = true;
        recPath[curr] = true;

        for(int nbr : l[curr]){
            if(!vis[nbr]){
                if(isCycleDirDFS(nbr,vis,recPath)){
                    return true;
                }
            }
            else if(recPath[nbr]){
                // visited and in current path
                return true;
            }
        }
        recPath[curr] = false; // backtrack
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleDirDFS(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {

    Graph g(4);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<<"Cycle present or not : "<<g.isCycle()<<endl;

    return 0;
}
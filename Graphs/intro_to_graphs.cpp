#include<iostream>
#include<vector>
#include<list>

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

    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(int neigh : l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};
int main() {

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.printAdjList();
    return 0;
}
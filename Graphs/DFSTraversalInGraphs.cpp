#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph {
    int V; // No. of vertices
    list<int> *l; // Pointer to an array containing adjacency lists

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // Undirected Graph
    }

    void printAdjList() {
        for(int i = 0; i < V; i++) {
            cout << i << " -> ";
            for(int nbr : l[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(int u , vector<bool> &vis){  // 0(V + E)
        cout << u << " ";
        vis[u] = true;

        for(int v : l[u]){
            if(!vis[v]){ // v is our immediate neighbour
                dfsHelper(v , vis);
            }
        }   
    }

    void dfs(){  // 0(V + E)
        int src = 0;
        vector<bool> vis(V, false);

        // for(int i = 0 ; i<V ;  i++) { // for disconnected components
        //     if(!vis[i]){
        //         dfsHelper(i , vis);
        //     }
        // }

        dfsHelper(src , vis);
        cout << endl;
    }
};
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printAdjList();

    cout<< "The DFS Traversal For The Graph is " , g.dfs();    

    return 0;
}
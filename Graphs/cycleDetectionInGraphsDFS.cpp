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

    bool isCycleUndirected(int src, int parent, vector<bool> &vis) { // 0(V + E)
        vis[src] = true;

        for(int v : l[src]) {
            if(!vis[v]) { // v is our immediate neighbour
                if(isCycleUndirected(v, src, vis)) {
                    return true;
                }
            } else if(v != parent) { // if the neighbour is visited and is not the parent of current node
                return true; // cycle found
            }
        }
        return false;
    }

    bool isCycle () {
        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) { // for disconnected components
                if(isCycleUndirected(i, -1, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    g.printAdjList();
   
    g.isCycle() ? cout << "Cycle Present" << endl : cout << "No Cycle Present" << endl;
    return 0;
}
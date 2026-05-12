#include<iostream>
#include<list>
#include<vector>

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
};
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjList();

    return 0;
}
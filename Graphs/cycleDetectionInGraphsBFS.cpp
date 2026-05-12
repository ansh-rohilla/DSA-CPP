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

    bool isCycleUndirBFS(int src, vector<bool> &vis) { // BFS CODE
        queue<pair<int, int>> q; // {node, parent}
        q.push({src, -1});
        vis[src] = true;

        while(!q.empty()) {
            int u = q.front().first;
            int par = q.front().second;
            q.pop();

            for(int v : l[u]) {
                if(!vis[v]) { // v is our immediate neighbour
                    q.push({v, u});
                    vis[v] = true;
                } else if(par != v) { // if visited and not parent
                    return true; // cycle present
                }
            }
        }
        return false; // cycle not present
    }

    bool isCycle() {
        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) { // if not visited
                if(isCycleUndirBFS(i, vis)) {
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
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

    void bfs(){  // 0(V + E)
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            cout << u << " ";

            for(int v : l[u]){
                if(!vis[v]){ // v is our immediate neighbour
                    q.push(v);
                    vis[v] = true;
                }
            }
        }   
        cout << endl;
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

    cout<< "The BFS Traversal For The Graph is " , g.bfs();    

    return 0;
}
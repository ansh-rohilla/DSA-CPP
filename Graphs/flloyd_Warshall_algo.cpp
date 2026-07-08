#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int> >> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        // adj[v].push_back({u, wt}); // undirected graph
    }

    void floydWarshall(){
        const int INF = 1e9; // Define a large value for infinity

        vector<vector<int>> dist(V, vector<int>(V, INF));

        for(int i = 0; i < V; i++) {
            dist[i][i] = 0; // Distance to self is zero
        }

        for(int u = 0; u < V; u++) {
            for(auto edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                dist[u][v] = min(dist[u][v], wt); // Handle multiple edges
            }
        }

        for(int k = 0; k < V; k++) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    if(dist[i][k] < INF && dist[k][j] < INF) { // Check to avoid overflow
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        cout << "Shortest distances between every pair of vertices:\n";
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";  
                }
            }
            cout << endl;
        }

        //negative cycle detection
        for(int i = 0; i < V; i++) {
            if(dist[i][i] < 0) {
                cout << "Negative weight cycle detected!" << endl;
                return;
            }
        }
    }

};


int main() {
    Graph g(4);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 11);
    g.addEdge(1, 2, 2);
    g.addEdge(3, 1, -8);
    g.addEdge(2, 3, 3);
    g.floydWarshall();
    return 0;
}
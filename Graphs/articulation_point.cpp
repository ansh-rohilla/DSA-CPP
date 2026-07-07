#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    int V;
    int timer;
    vector<int> dt, low;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parent, vector<bool> &isAP) {
        dt[u] = low[u] = ++timer;
        int children = 0;

        for (int v : adj[u]) {
            if (dt[v] == -1) {
                children++;
                dfs(v, u, isAP);

                low[u] = min(low[u], low[v]);

                // Non-root articulation point
                if (parent != -1 && low[v] >= dt[u]) {
                    isAP[u] = true;
                }
            }
            else if (v != parent) {
                // Back edge
                low[u] = min(low[u], dt[v]);
            }
        }

        // Root articulation point
        if (parent == -1 && children > 1) {
            isAP[u] = true;
        }
    }

    int articulationPoints() {
        timer = 0;
        dt.assign(V, -1);
        low.assign(V, -1);

        vector<bool> isAP(V, false);

        for (int i = 0; i < V; i++) {
            if (dt[i] == -1) {
                dfs(i, -1, isAP);
            }
        }

        int count = 0;
        cout << "Articulation Points: ";

        for (int i = 0; i < V; i++) {
            if (isAP[i]) {
                cout << i << " ";
                count++;
            }
        }

        cout << endl;
        return count;
    }
};

int main() {
    Graph g(6);

    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 1);

    cout << "Number of articulation points: "
         << g.articulationPoints() << endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topoSort(int curr, vector<bool> &visited, stack<int> &s) {
        visited[curr] = true;
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                topoSort(neighbor, visited, s);
            }
        }
        s.push(curr);
    }

    void dfs(int curr, vector<bool> &visited, vector<vector<int>> &transposed) {
        visited[curr] = true;
        cout << curr << " ";
        for (int neighbor : transposed[curr]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, transposed);
            }
        }
    }

    void kosaraju() { //O(V+E)
        stack<int> s;
        vector<bool> visited(V, false);

        // Step 1: Fill vertices in stack according to their finishing times
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoSort(i, visited, s);
            }
        }

        //step 2: Create a transposed graph
        vector<vector<int>> transposed(V);
        for (int u = 0; u < V; u++) {
            visited[u] = false; // Reset visited for the second DFS
            for (int v : adj[u]) {
                transposed[v].push_back(u);
            }
        }

        // Step 3: Now process all vertices in order defined by Stack
        while(!s.empty()) {
            int curr = s.top();
            s.pop();
            if (!visited[curr]) {
                cout << "SCC: ";
                dfs(curr, visited, transposed);
                cout << endl;
            }
        }
    }

};


int main() {
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.kosaraju();
    return 0;
}
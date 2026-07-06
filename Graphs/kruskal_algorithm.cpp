#include<iostream>
#include<vector>

using namespace std;

class Edge {  
public:
    int u, v, wt;

    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    //comparator function to sort edges based on weight
    bool operator<(const Edge& other) const {
        return this->wt < other.wt;
    }

};

class Graph {
public:
    int V;                  
    vector<Edge> edges;
    vector<int> parent, rank;

    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]); // path compression
    }

    void unionByRank(int x, int y) {
        int parX = find(x);
        int parY = find(y);

        if (parX == parY) {
            return;
        }

        if (rank[parX] < rank[parY]) {
            parent[parX] = parY;
        } else if (rank[parX] > rank[parY]) {
            parent[parY] = parX;
        } else {
            parent[parY] = parX;
            rank[parX]++;
        }
    }

    void kruskalMST() { //O(ElogE)
        sort(edges.begin(), edges.end());
        int totalWeight = 0;
        int edgeCount = 0;

        for (auto edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;

            if (find(u) != find(v)) {
                unionByRank(u, v);
                totalWeight += wt;
                edgeCount++;
                cout << "Edge: " << u << " - " << v << " Weight: " << wt << endl;
            }
        }

        cout << "Total weight of MST is: " << totalWeight << endl;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,6);
    graph.addEdge(0,3,5);
    graph.addEdge(1,3,15);
    graph.addEdge(2,3,4);

    graph.kruskalMST();

    return 0;
}
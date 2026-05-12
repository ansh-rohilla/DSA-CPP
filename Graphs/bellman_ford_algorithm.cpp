#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Edge {
public:
    int v;
    int wt;
    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int src , vector<vector<Edge>>& g , int V) {
    // Implementation goes here
    // Note: Bellman-Ford algorithm can handle negative weights but not negative weight cycles.
    // This implementation assumes no negative weight cycles are present in the graph.
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    // Relax all edges V-1 times
    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(Edge e : g[u]){
                int v = e.v;
                int wt = e.wt;

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    // print shortest distance from src to all other vertices
    for(int i=0;i<V;i++){
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
    }
}


int main(){

    int V = 5;
    vector<vector<Edge>> g(V);

    // add edges

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(4, -1));
    g[1].push_back(Edge(2, -4));

    g[2].push_back(Edge(3, 2));
    g[3].push_back(Edge(4, 4));

    bellmanFord(0, g, V);
    return 0;

}
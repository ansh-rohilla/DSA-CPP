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

void dijkstra(int src, vector<vector<Edge>>& g , int V) {
    // Implementation goes here
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {dist[u] , u}
    pq.push({0, src});  

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(Edge e : g[u]){ // explore all nbrs of u , edge relaxation
            int v = e.v;
            int wt = e.wt;

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    // print shortest distance from src to all other vertices
    for(int i=0;i<V;i++){
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
    }
}


int main(){

    int V = 6;
    vector<vector<Edge>> g(V);

    // add edges

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    dijkstra(0, g, V);
    return 0;

}
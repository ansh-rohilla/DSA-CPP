#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

int primMST(int V, vector<vector<pair<int, int>>> adj) {
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src = 0;
    pq.push({0, src});
    int totalWeight = 0;
    while (pq.size() > 0 ) {
        auto front = pq.top();
        int weight = front.first;
        int u = front.second;
        pq.pop();

        if (!inMST[u]) {
            inMST[u] = true;
            totalWeight += weight;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }
    }
    return totalWeight;
}

int main() {

    int V = 4;
    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({3, 30});
    adj[3].push_back({0, 30});

    adj[0].push_back({2, 15});
    adj[2].push_back({0, 15});

    adj[1].push_back({3, 40});
    adj[3].push_back({1, 40});

    adj[2].push_back({3, 50});
    adj[3].push_back({2, 50});

    cout << "Total weight of MST is: " << primMST(V, adj) << endl;
    return 0;
}
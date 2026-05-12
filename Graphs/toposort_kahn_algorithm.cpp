#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph {
    int V; // no of vertices
    list<int> *l; // dynamic array of lists 

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }
    void addEdge(int u , int v){
        l[u].push_back(v); // only directed graph
    }

    void topoSort(){
        vector<int> result;
        // 1) calcuating in degree of each node
        vector<int> inDegree(V,0);
        for(int u=0;u<V;u++){
            for(int v : l[u]){
                inDegree[v]++;
            }
        }

        // 2) push all nodes with inDegree 0 into the queue
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
    }

        // 3) BFS
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            // explore nbrs of curr
            for(int v : l[curr]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        // print result
        for(int node : result){
            cout << node << " ";
        }
        cout << endl;
    }
    
};
int main() {

    Graph g(6);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    g.topoSort();
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

class DisJointSetUnion {
    public:
    int n;
    vector<int> par, rank;

    DisJointSetUnion(int n) {
        this->n = n;

        for (int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]); // path compression can be applied here for optimization
    }

    void unionByRank(int x, int y) {
        int parX = find(x);
        int parY = find(y);

        if (parX == parY) {
            return;
        }

        if (rank[parX] < rank[parY]) {
            par[parX] = parY;
        } else if (rank[parX] > rank[parY]) {
            par[parY] = parX;
        } else {
            par[parY] = parX;
            rank[parX]++;
        }
    }

    void getInfo() {
        for (int i = 0; i < n; i++) {
            cout << par[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DisJointSetUnion dsu(6);

    dsu.unionByRank(0, 2);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(1,3);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(0,4);

    dsu.getInfo();

    return 0;
}
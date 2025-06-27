#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;

   
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }

   
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }


   
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; 
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};


void kMst(int V, vector<tuple<int, int, int>>& edges) {
    
    sort(edges.begin(), edges.end());

    UnionFind uf(V); 
    vector<tuple<int, int, int>> mst; 
    int totalWeight = 0; 

    for (auto& edge : edges) {
        int w = get<0>(edge); 
        int u = get<1>(edge); 
        int v = get<2>(edge); 

       
        if (uf.unite(u, v)) {
            mst.push_back(edge);
            totalWeight += w;
        }
    }

    
    cout << "Edges Mst:\n";
    for (auto& edge : mst) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        cout << u << " - " << v << " : " << w << endl;
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter num of ver and edg: ";
    cin >> V >> E;

 
    vector<tuple<int, int, int>> edges;

    cout << "Enter edges (u v w) \n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v}); 
    }

    kMst(V, edges);

    return 0;
}
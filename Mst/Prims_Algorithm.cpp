#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX


void pmst(vector<vector<pair<int, int>>> &adj, int V) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    
    vector<bool> visited(V, false);
    
   
    vector<int> key(V, INF);
    
    
    vector<int> parent(V, -1);
    
    

    pq.push({0, 0}); 
    key[0] = 0;
    
    while (!pq.empty()) {
        
        int u = pq.top().second;
        pq.pop();
        
       
        if (visited[u]) continue;
        
        
        visited[u] = true;
        
        
        for (auto &edge : adj[u]) {
            int v = edge.first; 
            int weight = edge.second; 
            
            
            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    
    cout << " Spanning Tree:\n";
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }
}




int main() {
    int V, E;
    cout << "number of ver and edg: ";
    cin >> V >> E;
   
    vector<vector<pair<int, int>>> adj(V);
    
    cout << "Enter edges \n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    
    pmst(adj, V);
    
    return 0;
}
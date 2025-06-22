#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// ------------------ Topological Sort ------------------
vector<int> topologicalSort(int n, vector<pair<int, int>>& deps) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for (auto [u, v] : deps) {
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (auto v : adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }

    if (order.size() != n) {
        cout << "Cycle in task dependencies!\n";
        return {};
    }
    return order;
}

// ------------------ Bellman-Ford ------------------
void bellmanFord(int n, vector<tuple<int, int, int>>& edges, int src) {
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "Bellman-Ford distances from node " << src << ":\n";
    for (int i = 0; i < n; i++){
        cout << "Node " << i << ": ";
        if(dist[i]>=INF){cout<< INF;}
        else{cout<<to_string(dist[i]);}
        cout<<"\n";
    }
}

// ------------------ Floyd-Warshall ------------------
void floydWarshall(int n, vector<vector<int>>& mat) {
    for (int via = 0; via < n; via++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][k] < INF && mat[k][j] < INF){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    // setw(6)
// This sets the width of the output column to 6 characters for alignment.
// Ensures all entries (like 1, 100, or "INF") line up properly in a grid.
    cout << "Floyd-Warshall All-Pairs Shortest Paths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << setw(6);    
            if(mat[i][j]>=INF){cout<< INF;}
            else{cout<<to_string(mat[i][j]);}
        }
        cout<<"\n";
    }
}

// ------------------ Main Driver ------------------
int main() {
    // Task scheduling via Topological Sort
    int taskCount = 6;
    // deps=dependecies
    vector<pair<int, int>> deps = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    auto order = topologicalSort(taskCount, deps);
    if (!order.empty()) {
        cout << "Topological Order of Tasks:\n";
        for (int task : order) cout << task << " ";
        cout << "\n";
    }

    // Delivery Optimization via Bellman-Ford
    int nodeCount = 5;
    vector<tuple<int, int, int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };
    bellmanFord(nodeCount, edges, 0);

    // Global Logistics using Floyd-Warshall
    vector<vector<int>> matrix = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };
    floydWarshall(4, matrix);

    return 0;
}

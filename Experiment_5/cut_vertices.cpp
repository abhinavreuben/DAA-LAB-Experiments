#include <iostream>
#include <vector>
using namespace std;

void DFS(int u, int parent, vector<vector<int>>& adj,
         vector<int>& discovery, vector<int>& low,
         vector<bool>& visited, vector<bool>& articulation,
         int& timer) {

    visited[u] = true;
    discovery[u] = low[u] = timer;
    timer++;

    int children = 0;
    for (int v : adj[u]) {

        if (v == parent)
            continue;

        if (!visited[v]) {
            children++;
            DFS(v, u, adj, discovery, low,
                visited, articulation, timer);
            if (low[v] < low[u])
                low[u] = low[v];
            if (parent != -1 && low[v] >= discovery[u])
                articulation[u] = true;
        }

        else {

            if (discovery[v] < low[u])
                low[u] = discovery[v];
        }
    }

    if (parent == -1 && children > 1)
        articulation[u] = true;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter edges:\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> discovery(V, -1);
    vector<int> low(V, -1);
    vector<bool> visited(V, false);
    vector<bool> articulation(V, false);

    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, -1, adj, discovery, low,
                visited, articulation, timer);
        }
    }
    cout << "\nCut Vertices: ";

    bool found = false;
    for (int i = 0; i < V; i++) {
        if (articulation[i]) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";
    cout << endl;
    return 0;
}

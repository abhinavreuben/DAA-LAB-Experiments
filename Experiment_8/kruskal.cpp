#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Find parent of a vertex
int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent, parent[x]);
}

// Union two sets
void unionSet(vector<int>& parent, vector<int>& rank,
              int u, int v) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void kruskalMST(vector<Edge>& edges, int V) {

    // Sort edges according to weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalWeight = 0;
    int edgesUsed = 0;
    cout << "\nKruskal's MST:\n"; 
    for (Edge e : edges) {

        int u = findParent(parent, e.u);
        int v = findParent(parent, e.v);

        // Include edge only if it doesn't form a cycle
        if (u != v) {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            totalWeight += e.weight;
            unionSet(parent, rank, u, v);
            edgesUsed++;
            if (edgesUsed == V - 1)
                break;
        }
    }
    cout << "Total weight = " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }
    kruskalMST(edges, V);
    return 0;
}

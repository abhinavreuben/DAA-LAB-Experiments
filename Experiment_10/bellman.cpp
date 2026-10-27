#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    cout << "Enter source, destination and weight of each edge:\n";
    for (int i = 0; i < E; i++) 
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    vector<int> dist(V, 1000000000);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            if (dist[u] != 1000000000 &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].weight;

        if (dist[u] != 1000000000 &&
            dist[u] + w < dist[v]) {
            cout << "Negative-weight cycle detected!\n";
            return 0;
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++) {
        if (dist[i] == 1000000000)
            cout << "Vertex " << i << ": Unreachable\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << "\n";
    }
    cout << "No negative-weight cycle detected.\n";
    return 0;
}

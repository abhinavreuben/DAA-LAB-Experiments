#include <iostream>
#include <vector>
using namespace std;

void dijkstra(int n, vector<vector<int>>& graph, int src) {
    vector<int> dist(n, 1000000000);
    vector<bool> visited(n, false);
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        if (u == -1 || dist[u] == 1000000000)
            break;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex\tShortest Distance\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t";
        if (dist[i] == 1000000000)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int n, src;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }
    cout << "Enter source vertex: ";
    cin >> src;
    dijkstra(n, graph, src);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int from;
    int to;
    long long cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        Edge e;
        e.from = u;
        e.to = v;
        e.cost = w;

        edges.push_back(e);
    }

    long long INF = 1000000000000000000LL;

    vector<long long> dist(n + 1, INF);

    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            long long w = edges[j].cost;

            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j].from;
        int v = edges[j].to;
        long long w = edges[j].cost;

        if (dist[u] != INF && dist[v] > dist[u] + w) {
            cout << "Negative cycle";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "inf";
        } else {
            cout << dist[i];
        }

        if (i < n) {
            cout << " ";
        }
    }

    return 0;
}
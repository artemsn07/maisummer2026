#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<pair<int, int>>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> width(n + 1, 0);

    priority_queue<pair<int, int>> q;

    width[s] = 1000000000;
    q.push({width[s], s});

    while (!q.empty()) {
        int currentWidth = q.top().first;
        int v = q.top().second;
        q.pop();

        if (currentWidth < width[v]) {
            continue;
        }

        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].first;
            int edgeWidth = g[v][i].second;

            int newWidth;

            if (width[v] < edgeWidth) {
                newWidth = width[v];
            } else {
                newWidth = edgeWidth;
            }

            if (newWidth > width[to]) {
                width[to] = newWidth;
                q.push({width[to], to});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == s) {
            cout << -1 << " ";
        } else {
            cout << width[i] << " ";
        }
    }

    return 0;
}
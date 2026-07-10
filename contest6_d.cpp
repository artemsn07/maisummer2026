#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, start, finish;
    cin >> n >> m >> start >> finish;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[finish] = 0;
    q.push(finish);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];

            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    if (dist[start] == -1) {
        cout << -1;
        return 0;
    }

    int current = start;

    cout << current << " ";

    while (current != finish) {
        for (int i = 0; i < g[current].size(); i++) {
            int to = g[current][i];

            if (dist[to] == dist[current] - 1) {
                current = to;
                cout << current << " ";
                break;
            }
        }
    }

    return 0;
}
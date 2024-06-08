#include <bits/stdc++.h>
using namespace std;
// Use Bellman Ford Algorithm to detect negative cycle

int main() {
    long long int n, m;
    cin >> n >> m;
    vector<vector<long long int>> edges;
    for (int i = 0; i < m; i++) {
        long long int n1, n2, w;
        cin >> n1 >> n2 >> w;
        edges.push_back({n1, n2, w});
    }
    vector<long long int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    vector<long long int> parent(n + 1, -1);
    long long int vertexInCycle = 0;
    for (int i = 1; i <= n; i++) {
        vertexInCycle = 0;
        for (auto &e : edges) {
            long long int n1 = e[0];
            long long int n2 = e[1];
            long long int w = e[2];
            if ( dist[n1] + w < dist[n2]) {
                
                dist[n2] = dist[n1] + w;
                parent[n2] = n1;
                if (i == n) {
                    vertexInCycle = n2;
                }
            }
        }
    }

// If a negative cycle is detected, then we can find a vertex within the cycle
// and then trace back to find the cycle
// If a negative cycle is not detected, then we can't find a cycle
    if (vertexInCycle) {
        cout << "YES" << endl;
        // To ensure we get a vertex within the cycle
        for (int i = 0; i < n; ++i) {
            vertexInCycle = parent[vertexInCycle];
        }
        vector<long long int> cycle;
        long long int startPoint = vertexInCycle;
        do {
            cycle.push_back(vertexInCycle);
            vertexInCycle = parent[vertexInCycle];
        } while (vertexInCycle != startPoint);
        cycle.push_back(startPoint);
        reverse(cycle.begin(), cycle.end());

        for (auto x : cycle) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

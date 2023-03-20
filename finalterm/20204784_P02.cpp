#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

long long d[32][N];

const long long inf = LLONG_MAX / 3;

vector<int> impl; 

vector<pair<int, long long>> graph[N];

bool vis[N];

int n, k, m;

long long Steiner()
{
    for (int i = 0; i < (1 << k); i++)
        fill(d[i], d[i] + N, inf);
    for (int i = 0; i < k; ++i) {
        d[1 << i][impl[i]] = 0;
    }
    priority_queue<pair<long long, int>> pqueue;
    for (int mask = 1; mask < (1 << k); ++mask) {
        for (int a = 0; a < mask; ++a) {                                                     
            int b = mask ^ a;
            if (b > a)
                continue;
            for (int v = 0; v < n; ++v) {
                d[mask][v] = min(d[mask][v], d[a][v] + d[b][v]);
            }
        }
        memset(vis, 0, sizeof vis);
        for (int vertex = 0; vertex < n; ++vertex) {
            if (d[mask][vertex] == inf)
                continue;
            pqueue.emplace(-d[mask][vertex], vertex);
        }
        while (!pqueue.empty()) {
            long long cost = -pqueue.top().first;
            int v = pqueue.top().second;
            pqueue.pop();
            if (vis[v])
                continue;
            vis[v] = true;
            for (auto edge : graph[v]) {
                long long ec = cost + edge.second;
                if (ec < d[mask][edge.first]) {
                    d[mask][edge.first] = ec;
                    pqueue.emplace(-ec, edge.first);
                }
            }
        }
    }
    long long res = inf;
    for (int v = 0; v < n; ++v) {
        res = min(res, d[(1 << k) - 1][v]);
    }
    return res;
}

void makeGraph() {
    for (int i = 0; i < m; ++i) {
        int node, vertex;
        long long weight;
        cin >> node >> vertex >> weight;
        --node;
        --vertex;
        graph[node].emplace_back(vertex, weight);
        graph[vertex].emplace_back(node, weight);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    makeGraph();

    cin >> k;
    impl.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> impl[i];
        --impl[i];
    }
    cout << Steiner() << '\n';
    return 0;
}
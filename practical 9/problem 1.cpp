#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
bool visited[100];

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int next : adj[node]) {
        if (!visited[next])
            DFS(next);
    }
}

void BFS(int start, int n) {
    bool vis[100] = {false};
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next : adj[node]) {
            if (!vis[next]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, u, v, start;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> start;

    cout << "DFS: ";
    DFS(start);

    cout << "\nBFS: ";
    BFS(start, n);

    return 0;
}
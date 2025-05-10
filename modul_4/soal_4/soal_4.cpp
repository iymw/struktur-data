#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, int S, vector<int>& par, vector<int>& dist) {
    queue<int> q;
    dist[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : graph[node]) {
            if (dist[neighbour] == 1e9) {
                par[neighbour] = node;
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }
}

void printShortestDistance(vector<vector<int>>& graph, int S, int D, int V, unordered_map<int, int>& um) {
    vector<int> par(V, -1);

    vector<int> dist(V, 1e9);

    bfs(graph, S, par, dist);

    if (dist[D] == 1e9) {
        return;
    }

    vector<int> path;
    int currentNode = D;
    path.push_back(D);
    while (par[currentNode] != -1) {
        path.push_back(par[currentNode]);
        currentNode = par[currentNode];
    }

    for (int i = path.size() - 1; i >= 0; i--) cout << um[path[i]] << " ";
}

int main() {
    int a, b, v = 6, nums = v, x = 0;
    vector<int> temp;
    vector<vector<int>> adj(v), edges;
    unordered_map<int, int> um, reverse_um;

    while (nums >= 1) {
        cin >> a >> b;

        if (um.find(a) == um.end()) {
            um[a] = x;
            reverse_um[x] = a;
            x++;
        }
        if (um.find(b) == um.end()) {
            um[b] = x;
            reverse_um[x] = b;
            x++;
        }

        temp.push_back(um[a]);
        temp.push_back(um[b]);
        edges.push_back(temp);
        temp.clear();

        adj[um[a]].push_back(um[b]);

        nums--;
    }

    string input;
    cin >> input;

    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << reverse_um[i] << " " << reverse_um[adj[i][j]] << " ";
        }
        cout << "\n";
    }

    vector<vector<int>> graph(v);
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    printShortestDistance(graph, edges[0][0], edges[5][1], v, reverse_um);
    return 0;
}
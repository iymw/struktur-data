#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
using namespace std;

void displayFastestPath(map<int, int>& parent, int destination) {
    vector<int> path;
    int current = destination;

    while (current != -1) {
        path.insert(path.begin(), current);
        current = parent[current];
    }

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    map<int, vector<int>> graph;
    string input;

    int maxVertex = -1;

    while (getline(cin, input)) {
        if (input == "stop") {
            break;
        }
        stringstream ss(input);
        int vertex, edge;
        ss >> vertex >> edge;
        graph[vertex].push_back(edge);

        maxVertex = max(maxVertex, max(vertex, edge));
    }

    for (auto it = graph.begin(); it != graph.end(); ++it) {
        cout << it->first << " ";
        for (int j = 0; j < it->second.size(); ++j) {
            cout << it->second[j];
            if (j != it->second.size() - 1) {
                cout << " " << it->first << " ";
            }
        }
        cout << endl;
    }

    cout << endl;

    if (!graph.empty()) {
        queue<int> q;
        map<int, bool> visited;
        map<int, int> parent;

        int start = graph.begin()->first;
        int destination = maxVertex;

        q.push(start);
        visited[start] = true;
        parent[start] = -1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == destination) {
                displayFastestPath(parent, destination);
                break;
            }

            for (int i = 0; i < graph[current].size(); ++i) {
                if (!visited[graph[current][i]]) {
                    q.push(graph[current][i]);
                    visited[graph[current][i]] = true;
                    parent[graph[current][i]] = current;
                }
            }
        }
    }

    return 0;
}
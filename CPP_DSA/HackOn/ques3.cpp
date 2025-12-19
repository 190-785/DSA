#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

vector<int> bfs_sequence(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    vector<int> sequence;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        sequence.push_back(u);
        
        vector<int> neighbors;
        for (const auto& edge : graph[u]) {
            if (!visited[edge.first]) {
                neighbors.push_back(edge.first);
            }
        }
        
        sort(neighbors.begin(), neighbors.end());
        
        for (int v : neighbors) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    return sequence;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    if (n == 0 || m == 0) {
        cout << -1 << endl;
        return 0;
    }
    
    vector<vector<pair<int, int>>> graph(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    int source;
    cin >> source;
    
    vector<int> bfs_order = bfs_sequence(source, graph);
    
    if (bfs_order.size() < 2) {
        cout << -1 << endl;
        return 0;
    }
    
    int first_node = bfs_order[0];
    int last_node = bfs_order[bfs_order.size() - 1];
    
    vector<int> distances = dijkstra(first_node, graph);
    
    if (distances[last_node] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << distances[last_node] << endl;
    }
    
    return 0;
}
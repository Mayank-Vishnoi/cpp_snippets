const int INF = 1e8;

// Read more on https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html
vector<vector<int>> floyd_marshall (vector<vector<int>>& edges) {    
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (auto &[u, v, w]: edges) {
      d[u][v] = w;
      d[v][u] = w;
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
      }
    }
    return d; // distance matrix
}
// Safety check for negative edges
if (d[i][k] < INF && d[k][j] < INF)
  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


vector<int> bellman_ford (int src) {
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int i = 0; i <= k; i++) {
      vector<int> new_dist(dist);
      for (auto &[u, v, w] : edges) {
        new_dist[v] = min(new_dist[v], dist[u] + w);
      }
      dist = new_dist;
    }
    return dist; // min distance to every node in max k steps
  }
}
// It will take maximum k = n - 1 for finding shortest distances

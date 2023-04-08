// dfs
vector<bool> vis(n + 1, 0);
function<void(int)> dfs = [&] (int u) {
   for (auto v : adj[u]) {
      if (vis[v]) continue;
      vis[v] = 1;
      dfs(v);
   }
};
vis[1] = 1;
dfs(1);

// bfs
vector<int> dist(n + 1, -1);
queue<int> q;
q.push(1);
dist[1] = 0;
while (!q.empty()) {
   int u = q.front();
   q.pop();
   for (auto v : adj[u]) {
      if (dist[v] == -1) {
         dist[v] = dist[u] + 1;
         q.push(v);
      }
   }
}

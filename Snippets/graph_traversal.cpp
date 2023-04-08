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

int dx[]{0, 0, 1, -1}, dy[]{1, -1, 0, 0};

// bfs on grid
// maintain a parent array to trace back the shortest path found
// use a deque in the case where weights can only be 0/1 
vector<vector<int>> dist(n, vector<int>(m, -1));
queue<pair<int, int>> q;
q.push({0, 0});
dist[0][0] = 0;
while (!q.empty()) {
   auto [x, y] = q.front();
   q.pop();
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist[nx][ny] != -1 || g[nx][ny] != 1) continue;
      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
   }
}

// flood fill on grid
// use a component array and additional parameter to find connected regions
vector<vector<int>> vis(n, vector<int>(m, 0));
function<void(int, int)> dfs = [&](int x, int y) {
   vis[x][y] = 1;
   cout << x << ' ' << y << '\n';
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] || g[nx][ny] != 1) continue;
      dfs(nx, ny);
   }
};
dfs(0, 0);

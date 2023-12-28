auto  dijkstra = [&](int s, vi & dist, vi & path) {
    dist.assign(n, inf);
    path.assign(n, -1);

    dist[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                q.erase({dist[to], to});
                dist[to] = dist[v] + len;
                path[to] = v;
                q.insert({dist[to], to});
            }
        }
    }
};
auto restore_path = [&](int s, int t, vector<int> const & p) {
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
};

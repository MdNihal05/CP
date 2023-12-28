vector<int>dist(n + 1, inf), vis(n + 1);
    set<pair<int, int>>pq;
    pq.insert({0, 1});
    dist[1] = 0;
    while (pq.size()) {
        auto [u, v] = *pq.begin();
        if (vis[v]) continue;
        vis[v] = 1;
        pq.erase(pq.begin());
        for (auto &child : graph[v]) {
            int x = child.first;
            int y = child.second;
            if (dist[v] + y < dist[x]) {
                dist[x] = dist[v] + y;
                pq.insert({dist[x], x});
            }
        }
    }

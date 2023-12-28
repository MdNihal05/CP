class dijkstra {
    vi dist, path;
    int n;
public:
    dijkstra(vector<vector<pair<int, int>>>graph, int source) {
        n = graph.size();
        dist.assign(n+1, inf);
        path.assign(n+1, -1);
        dist[source] = 0;
        set<pair<int, int>> q;
        q.insert({0, source});
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
    }
    int distance(int to) {
        return dist[to];
    }
    vi restore_path(int s, int t) {
        vector<int> p;
        for (int v = t; v != s; v = path[v])
            p.push_back(v);
        p.push_back(s);
        reverse(p.begin(), p.end());
        return p;
    };

};

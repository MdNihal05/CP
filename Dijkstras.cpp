vector<int> dist(n + 1, inf); vector<bool> visited(n + 1), parent(n + 1, -1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int source = 1; /// change source element
	dist[source] = 0;
	pq.push({0, source});
	while (!pq.empty()) {
		int dst = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (visited[node]) continue;
		visited[node] = true;
		for (auto [child, d] : graph[node]) {
			if (visited[child]) continue;
			dist[child] = min(dist[child], dst + d);
			pq.push({dist[child], child});
			parent[child] = node;
		}
	}
	if (dist[n] == MAX) {
		cout << -1;
		return;
	}
	vi path;
	while (source > 0) {
		path.push_back(source);
		source = parent[source];
	}
	reverse(all(path));

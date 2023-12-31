vector<int>dist(n + 1, MAX), par(n + 1, -1);
dist[1] = 0;
priority_queue < array<int, 2> , vector <array<int, 2>>, greater <array<int, 2>>>  pq ;
pq.push({0, 1}); // source

while (pq.size() > 0) {
    int node = pq.top()[1];
    pq.pop();
    for (auto &child : graph[node]) {
        int c_child = child.first;
        int ds = child.second;
        if (dist[c_child] > dist[node] + ds) {
            dist[c_child] = dist[node] + ds;
            pq.push({dist[c_child], c_child});
            par[c_child] = node;
        }

    }
}
if (dist[n] == MAX) {
    cout << -1;
    return;
}
int source = n; // source
vi ans;
while (source > 0) {
    ans.push_back(source);
    source = par[source];
}
reverse(all(ans));

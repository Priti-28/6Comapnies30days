class Solution
{
public:
    // Dijkstra Solution

    vector<pair<int, int>> adj[200];

    bool static cmp(const pair<int, int> a, const pair<int, int> b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    }

    void dijkstra(int src, int n, int distanceThreshold, vector<pair<int, int>> &ans)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dis(n + 1, INT_MAX);
        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int weigh = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                // In adj , {u, wt}
                int adj_node = it.first;
                int new_weigh = it.second;
                if (dis[adj_node] > dis[node] + new_weigh)
                {
                    dis[adj_node] = dis[node] + new_weigh;
                    pq.push({dis[adj_node], adj_node});
                }
            }
        }

        int count = 0;
        for (int i = 0; i < dis.size(); i++)
        {
            if (i != src && dis[i] <= distanceThreshold)
                count++;
        }
        ans.push_back({count, src});
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++)
        {
            dijkstra(i, n, distanceThreshold, ans);
        }

        sort(ans.begin(), ans.end(), cmp);

        return ans[0].second; // ans = {count, src}
    }
};
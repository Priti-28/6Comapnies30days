class Solution
{
private:
    /*
    Approach
    ---> Create a graph from the given original to changed items with edge-cost as cost    given. It will be a directed graph from original[i] to changed[i].

    ---> As we have a graph, we iterate over the source[i] and try to match with the target[i].

    ---> if both are matching then nothing to do
    ---> if not matching then call the getCost funtion to get the cost of the conversion from the source[i] to target[i].
    ---> if the cost is -1 then return -1 as its not possible to convert soure to target.
    ---> if the cost is not -1 then add it to our ans.
    ---> Also keep storing the result in a cost map for future use.
    ---> Now how to get the cost for source[i] to target[i]?


    */
   
    long long getCost(vector<vector<pair<char, int>>> &adj, int src, int end)
    {
        long long res = LONG_MAX;
        vector<long long> dis(26, LONG_MAX);
        dis[src] = 0;
        queue<pair<int, long long>> q;
        q.push({src, 0});

        while (!q.empty())
        {
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();

            for (auto it : adj[node]) // traversing all adjacent node
            {
                int adj_node = it.first;
                int adj_wt = it.second;
                if (cost + adj_wt >= dis[adj_node])
                    continue;
                q.push({adj_node, cost + adj_wt});
                dis[adj_node] = cost + adj_wt;
                if (adj_node == end)
                    res = cost + adj_wt;
            }
        }
        return (res == LONG_MAX) ? -1 : res;
    }

public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {

        long long ans = 0;
        unordered_map<long long, long long> costMap;
        // creating grap to store {u, {v, wt}} -> {original[i], {changed[i], cost[i]}}
        vector<vector<pair<char, int>>> graph(26);

        // Create the weighted directed graph
        for (int i = 0; i < cost.size(); i++)
        {
            graph[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] == target[i])
                continue;
            long long t = 0;
            long long hs = (source[i] - 'a') * 100 + target[i] - 'a';

            // check for the cost to make both string equal
            if (costMap.find(hs) != costMap.end())
                t = costMap[hs];
            else
            {
                t = getCost(graph, source[i] - 'a', target[i] - 'a');
                costMap[hs] = t;
            }
            if (t == -1)
                return -1;
            ans += t;
        }
        return ans;
    }
};
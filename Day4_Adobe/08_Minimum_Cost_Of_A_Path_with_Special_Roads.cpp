class Solution
{
public:
    // ------------------------------Dijkstra Algo------------------------------------------

    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = specialRoads.size();

        vector<int> distance(n, INT_MAX); // making dis vector like dikjkstra

        for (int i = 0; i < n; i++)
        {
            distance[i] = abs(start[0] - specialRoads[i][0]) + abs(start[1] - specialRoads[i][1]) + specialRoads[i][4];
            pq.push({distance[i], i}); // {distance, index}
        }

        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);

        while (!pq.empty())
        {
            int dis_curr = pq.top().first;
            int ind_curr = pq.top().second;
            pq.pop();

            if (dis_curr != distance[ind_curr])
                continue;

            ans = min(ans, dis_curr + abs(target[0] - specialRoads[ind_curr][2]) +
                               abs(target[1] - specialRoads[ind_curr][3]));

            for (int adj = 0; adj < n; adj++) // will traverse to all special roads named adj here
            {
                int w = abs(specialRoads[ind_curr][2] - specialRoads[adj][0]) +
                        abs(specialRoads[ind_curr][3] - specialRoads[adj][1]) + specialRoads[adj][4];
                if (dis_curr + w < distance[adj])
                {
                    distance[adj] = dis_curr + w;
                    pq.push({distance[adj], adj});
                }
            }
        }
        return ans;
    }
};
class Solution
{
public:
    // Brute force
    // Time = O(n *m)
    // Space = O(n *m)

    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        vector<vector<int>> directions{
            {-1, -1}, {-1, 0}, {-1, +1}, {0, -1}, {0, 0}, {0, +1}, {+1, -1}, {+1, 0}, {+1, +1}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int neigh_sum = 0;   // sum of all its surrounding neighbour
                int neigh_count = 0; // count the total number of neighbour present

                for (auto it : directions)
                {
                    int new_i = i + it[0];
                    int new_j = j + it[1];

                    if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < m)
                    {
                        neigh_sum += img[new_i][new_j];
                        neigh_count++;
                    }
                }
                ans[i][j] = neigh_sum / neigh_count;
            }
        }
        return ans;
    }
};
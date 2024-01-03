class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();
        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int siz = nums[0].size();
            vector<pair<string, int>> temp;
            for (int j = 0; j < n; j++)
            {
                string s = nums[j].substr(nums[j].length() - queries[i][1], queries[i][1]);
                temp.push_back({s, j});
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp[queries[i][0] - 1].second);
        }
        return ans;
    }
};

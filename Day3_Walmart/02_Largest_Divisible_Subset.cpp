class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        map<int, vector<int>> m;

        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            m.insert({nums[i], {nums[i]}});
            for (auto it : m)
            {
                if (nums[i] != it.first && (it.first % nums[i] == 0 || nums[i] % it.first == 0))
                {
                    if (it.second.size() + 1 > m[nums[i]].size())
                    {
                        vector<int> temp = it.second;
                        temp.push_back(nums[i]);
                        m[nums[i]] = temp;
                        if (m[nums[i]].size() > maxi)
                            maxi = m[nums[i]].size();
                    }
                }
            }
            if ((int)m[nums[i]].size() > maxi)
                maxi = (int)m[nums[i]].size();
        }

        vector<int> ans;
        for (auto it : m)
        {
            if (it.second.size() == maxi)
                return ans = it.second;
        }
        return ans;
    }
};
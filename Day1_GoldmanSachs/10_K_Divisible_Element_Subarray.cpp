class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {

        int n = nums.size();
        set<vector<int>> final_ans;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            vector<int> ans;
            for (int j = i; j < n; j++)
            {
                ans.push_back(nums[j]);
                if (nums[j] % p == 0)
                    count++;
                if (count > k)
                    break;
                final_ans.insert(ans);
            }
        }
        return final_ans.size();
    }
};
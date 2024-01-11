class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();

        int i = 0, t = k;

        vector<int> ans;

        // put first k elements
        while (t > 0)
        {
            ans.push_back(nums[i]);
            i++;
            t--;
        }

        // Loop for remaining element
        for (int j = i; j < n; j++)
        {
            // find minimum element from ans array
            auto mini = min_element(ans.begin(), ans.end()); // min_element returns an iterator.
            if (nums[j] > *mini)                             // *mini returns an address
            {
                ans.erase(mini);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};
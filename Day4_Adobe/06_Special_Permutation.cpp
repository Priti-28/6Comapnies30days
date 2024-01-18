class Solution
{
public:
    //-----------------------Brute Force(Recursion)----------------------------------------------------

    bool isspecial(vector<int> nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] % nums[i + 1] == 0 || nums[i + 1] % nums[i] == 0)
                continue;
            else
                return false;
        }
        return true;
    }

    void func(vector<int> &nums, vector<int> &ans, vector<vector<int>> &final_ans, int vis[], int n)
    {
        if (ans.size() == n)
        {
            if (isspecial(ans))
                final_ans.push_back(ans);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans.push_back(nums[i]);
                vis[i] = 1;
                func(nums, ans, final_ans, vis, n);
                vis[i] = 0;
                ans.pop_back();
            }
        }
    }
    int specialPerm(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> final_ans;
        vector<int> ans;

        int vis[n];
        for (int i = 0; i < n; i++)
            vis[i] = 0;

        func(nums, ans, final_ans, vis, n);

        return final_ans.size();
    }
};



//----------------------Methos 2--------------------------------------

const int mod = 1e9 + 7;

class Solution
{
public:
    //---------------------------Memoization with bit masking-------------------------------------------
    int func(int prevIndex, int mask, vector<vector<int>> &dp, int count, vector<int> &nums)
    {
        if (count == nums.size())
            return 1;

        // already computed
        if (dp[prevIndex][mask] != -1)
            return dp[prevIndex][mask];

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // already visited
            if (mask & (1 << i))
                continue;

            // atleast 1 elemetn se;lect previously
            if (mask != 0 && nums[i] % nums[prevIndex] != 0 &&
                nums[prevIndex] % nums[i] != 0)
                continue;

            // take element ans update ans
            ans = (ans + func(i, mask | (1 << i), dp, count + 1, nums)) % mod;
        }

        return dp[prevIndex][mask] = ans;
    }
    int specialPerm(vector<int> &nums)
    {
        int n = nums.size();
        // size of dp: (n, 2^n)
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));

        int mask = 0; // initally no element is selcted
        int prevIndex = 0;
        int count = 0;
        return func(prevIndex, mask, dp, count, nums);
    }
};
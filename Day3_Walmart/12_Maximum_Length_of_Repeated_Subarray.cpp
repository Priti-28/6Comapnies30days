class Solution
{
public:
    // -------------------------Recursive--------------------------------
    // Time = O(m * n * (m + n))
    // Space = O(m+n)

    int func(int i, int j, vector<int> &nums1, vector<int> &nums2)
    {
        if (i == 0 || j == 0)
            return 0;
        if (nums1[i - 1] == nums2[j - 1])
        {
            // if both matches thrn move both string like LCS
            return 1 + func(i - 1, j - 1, nums1, nums2);
        }

        return 0;
    }
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int res = func(i, j, nums1, nums2);
                ans = max(res, ans);
            }
        }
        return ans;
    }
};



class Solution
{
public:
    // -------------------------Memoization--------------------------------
    // Time = O(m * n )
    // Space = O(m+n)

    int func(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return dp[i][j] = 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (nums1[i - 1] == nums2[j - 1])
        {
            // if both matches thrn move both string like LCS
            return dp[i][j] = 1 + func(i - 1, j - 1, nums1, nums2, dp);
        }

        return dp[i][j] = 0;
    }
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int res = func(i, j, nums1, nums2, dp);
                ans = max(res, ans);
            }
        }
        return ans;
    }
};





class Solution
{
public:
    // -------------------------Tabulation--------------------------------
    // Time = O(m * n )
    // Space = O(m+n)

    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(dp[i][j], ans);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return ans;
    }
};
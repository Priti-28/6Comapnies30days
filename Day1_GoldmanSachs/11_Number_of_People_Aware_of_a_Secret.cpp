class Solution
{
    int dp[1001];
#define mod 1000000007
public:
    int solve(int day, int delay, int forget, int n)
    {
        if (day + delay > n)
            return 1;
        if (dp[day] != -1)
            return dp[day];
        int ans = 1;
        for (int i = day + delay; i <= min(n, day + forget); i++)
        {
            if (i == day + forget)
            {
                ans -= 1;
                break;
            }
            ans = (ans % mod + solve(i, delay, forget, n) % mod) % mod;
        }
        return dp[day] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        memset(dp, -1, sizeof(dp));
        return solve(1, delay, forget, n);
    }
};
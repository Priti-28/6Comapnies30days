class Solution
{
public:
// Not optimized (brute force but correct)

    int findTheWinner(int n, int k)
    {
        map<int, int> m;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            nums[i] = i + 1;
        }

        int count = 0;
        for (int i = 0; i <= n * n * k; i++)
        {
            if (m.size() == n - 1)
            {
                break;
            }

            if (m.find(nums[i % n]) == m.end())
            {
                count++;
                if (count == k)
                {
                    m.insert({nums[i % n], i % n});
                    count = 0;
                }
            }
            else if (m.find(nums[i % n]) != m.end())
            {
                continue;
            }
        }
        int ans;
        for (int i = 0; i < n; i++)
        {
            if (m.find(nums[i]) == m.end())
                ans = nums[i];
        }
        return ans;
    }
};


class Solution
{
public:
    // Two pointer approach , Space = O(1)

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0, odd = 0, count = 0, ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] % 2 != 0) // if nums[j] is odd
            {
                odd++;
                if (odd >= k)
                {
                    count = 1;
                    while (!(nums[i++] % 2 != 0))
                        count++; // jb tk nums[j] odd na mile, increase count
                    ans += count;
                }
            }
            else if (odd >= k)
                ans += count;
        }
        return ans;
    }
};
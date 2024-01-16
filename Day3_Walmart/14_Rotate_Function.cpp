
using namespace std;



class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        /*
        -------------------------------Time = O(N), Space= O(1)---------------------------------



                 4 3 2 6
                F(0) = 0*4 + 1*3 + 2*2 + 3*6 = 25
                f(1) = 0*6 + 1*4 + 2*3 + 3*2 = 16

                Observation:- F(1) = F(0) - Araay_sum - 4 * arr[3]
                              F(1) = 25   - (4+3+2+6) - 4 * 6
                                   = 25   + 15  - 24
                                   = 16

        ith rotation F(i) -> previous_sum = previous_sum + array_sum - (size * arr[size-1-i]);

        -----------------------------------------------------------------------------------------
        */

        int n = nums.size();
        int original_sum = 0, array_sum = 0;

        for (int i = 0; i < n; i++)
        {
            array_sum += nums[i];
            original_sum += i * nums[i];
        }

        int previous_sum = original_sum; // no need just for be more familiar with formula
        int ans = original_sum;

        for (int i = 0; i < n; i++)
        {
            previous_sum += array_sum - (n * nums[n - i - 1]);
            ans = max(ans, previous_sum);
        }
        return ans;
    }
};
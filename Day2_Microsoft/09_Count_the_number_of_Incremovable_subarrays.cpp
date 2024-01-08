class Solution
{
public:
    // Tc = O(N3)
    // Sc= O(1)
    // Brute force

    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int flag = 1;
                int last_index = -1; // storing last smaller element
                // k will check if the subarray from j->k is increasing or no
                for (int k = 0; k < n; k++)
                {
                    if (k >= i && k <= j)
                        continue;                   // if k is between i and j then skip,should be( i.j.k)
                    else if (nums[k] <= last_index) // no duplicay
                    {
                        flag = 0; // means not increasing sequence
                        break;
                    }
                    last_index = nums[k];
                }
                // flag is 1 means this subarray is in increasing sequence so count it in ans
                if (flag == 1) count++; 
            }
        }

        return count;
    }
};
class Solution
{
public:
    // -------------------------USING TWO POINTERS :---------------------------------------
    // TIME COMPLEXITY : O(NlogN)
    // SPACE COMPLEXITY : O(1)

    //------------------------------------------------------------------------------------

    
    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 0, i = 0, j = 1;

        for (i, j; i < n && j < n;)
        {
            if (i == j || nums[j] - nums[i] < k)
                j++;
            else
            {
                if (nums[j] - nums[i] == k) // if differenc equal to "k"
                {
                    count++;
                    j++; // incrementing j so we can compare nums[j] and nums[j-1]
                    // loop to skip duplicate numbers
                    for (; j < nums.size(); j++)
                    {
                        // if no duplicate number then break the loop
                        if (nums[j] != nums[j - 1])
                            break;
                    }

                    if (j == n)
                        return count; // if j reaches end in between then return
                    j--;              // in line 16 we increment it so , here e r decrementing
                }
                i++; // if difference is > k  then increement left side

                while (i < j and nums[i] == nums[i - 1])
                    i++; // to skip duplicate numbers
            }
        }
        return count;
    }
};
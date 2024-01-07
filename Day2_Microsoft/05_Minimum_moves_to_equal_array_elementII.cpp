class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();

        // sort the array
        sort(nums.begin(), nums.end());

        // take middle element of the array , try to make all elements equal tomiddle element
        int middle = nums[n / 2];
        int moves = 0;

        for (int i = 0; i < n; i++)
        {
            moves = moves + abs(nums[i] - middle);
        }
        return moves;
    }
};
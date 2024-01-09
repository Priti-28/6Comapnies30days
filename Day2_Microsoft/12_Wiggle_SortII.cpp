class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int i = (temp.size() - 1) / 2;
        int j = temp.size() - 1;
        int k = 0;

        while (k < nums.size())
        {
            if (k % 2 == 0) // even , wants smaller number
            {
                nums[k++] = temp[i--]; // moves from middle to left
            }
            else // odd, wants larger
            {
                nums[k++] = temp[j--]; // move from last to left
            }
        }
    }
};
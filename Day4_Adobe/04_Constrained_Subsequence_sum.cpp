class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;

        int ans = nums[0];
        for (int i = 0; i < n; i++)
        {
            // if dq is empty gives 0 else adding a[i] in previous
            nums[i] += dq.size() ? dq.front() : 0;
            // update maximum
            ans = max(ans, nums[i]);

            // Remove element smaller than current element from the dequeue from back
            while (dq.size() && nums[i] > dq.back())
                dq.pop_back();

            // if curr element is > 0 then push in the dequeue
            if (nums[i] > 0)
                dq.push_back(nums[i]);

            // remove element from front if they r out ot range ()
            if (i >= k && dq.size() && dq.front() == nums[i - k])
                dq.pop_front();
        }

        return ans;
    }
};
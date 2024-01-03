class Solution
{
public:
    void func(int ind, int target, int k, vector<int> &ans, vector<vector<int>> &final_ans)
    {
        if (target < 0 || ans.size() > k)
            return;
        if (target == 0 && ans.size() == k)
        {
            final_ans.push_back(ans);
            return;
        }
        for (int i = ind; i <= 9; i++)
        {
            ans.push_back(i);
            func(i + 1, target - i, k, ans, final_ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {

        vector<vector<int>> final_ans;
        vector<int> ans;
        func(1, n, k, ans, final_ans);
        return final_ans;
    }
};
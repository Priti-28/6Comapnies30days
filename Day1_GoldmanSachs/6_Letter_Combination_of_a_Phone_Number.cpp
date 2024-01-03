class Solution
{
public:
    void solve(int ind, string &ans, vector<string> &final_ans, map<char, string> &m, string digits)
    {
        if (ans.size() == digits.length())
        {
            final_ans.push_back(ans);
            return;
        }

        for (int i = 0; (digits[ind] == '7' || digits[ind] == '9') ? i < 4 : i < 3; i++)
        {
            string s = m[digits[ind]]; // abc
            ans.push_back(s[i]);       // a
            solve(ind + 1, ans, final_ans, m, digits);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};
        map<char, string> m;
        m.insert({'2', "abc"});
        m.insert({'3', "def"});
        m.insert({'4', "ghi"});
        m.insert({'5', "jkl"});
        m.insert({'6', "mno"});
        m.insert({'7', "pqrs"});
        m.insert({'8', "tuv"});
        m.insert({'9', "wxyz"});
        string ans;
        vector<string> final_ans;
        solve(0, ans, final_ans, m, digits);
        return final_ans;
    }
};
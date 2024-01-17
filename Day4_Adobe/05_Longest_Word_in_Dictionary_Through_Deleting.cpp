class Solution
{
public:
    // Same as LIS
    bool makingSubsequence(string a, string b)
    {
        // comparing a with b
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j]) // if both string matches
            {
                i++;
                j++;
            }
            else
                j++; //
        }
        return i == a.size(); // when a got completed
    }
    string findLongestWord(string s, vector<string> &dictionary)
    {

        string ans = "";
        for (auto &it : dictionary)
        {
            if (it.size() > ans.size() || (it.size() == ans.size() && it < ans))
            {
                // it = "aale" , s = "abpcplea",
                if (makingSubsequence(it, s))
                    ans = it;
            }
        }
        return ans;
    }
};
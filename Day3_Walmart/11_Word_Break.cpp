class Solution
{
public:
    // --------------------------------------------Recursion------------------------------------------

    bool func(int i, string s, set<string> &st)
    {
        if (i == s.size())
            return 1;

        string temp;
        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];                  // everytime we r adding 1 char in temp
            if (st.find(temp) != st.end()) // checking if that temp is available in st
            {
                if (func(j + 1, s, st) == true)
                    return 1; // then send j+1 to the recursive call func
            }
        }
        return 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        set<string> st;
        for (auto it : wordDict)
            st.insert(it); // so that it will be easy to find
        return func(0, s, st);
    }
};



class Solution
{
public:
    // --------------------------------------------Memoization------------------------------------------

    bool func(int i, string s, set<string> &st, vector<int> &dp)
    {
        if (i == s.size())
            return 1;

        if (dp[i] != -1)
            return dp[i];

        string temp;
        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];                  // everytime we r adding 1 char in temp
            if (st.find(temp) != st.end()) // checking if that temp is available in st
            {
                // then send j+1 to the recursive call func
                if (func(j + 1, s, st, dp) == true)
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        set<string> st;
        for (auto it : wordDict)
            st.insert(it); // so that it will be easy to find
        return func(0, s, st, dp);
    }
};
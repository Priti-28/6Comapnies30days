class Solution
{
public:
    // Memoization

    int func(int ind, string str, unordered_set<string> &s, vector<int> &dp)
    {
        if (ind >= str.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        // not take
        int not_take = 1 + func(ind + 1, str, s, dp);

        // take
        int take = 1e9;

        // Try to match substrings from the current index.
        for (int j = 1; j + ind <= str.size(); j++)
        {
            string t = str.substr(ind, j); // Extract a substring of length j from current position.
            if (s.find(t) != s.end())
                take = min(take, func(ind + j, str, s, dp)); // Check if this substring exists in set.
        }
        return dp[ind] = min(take, not_take);
    }

    int minExtraChar(string str, vector<string> &dictionary)
    {
        int n = dictionary.size();
        unordered_set<string> s;

        vector<int> dp(str.size() + 1, -1);
        // Insert all words from dic into a set for faster lookup
        for (auto it : dictionary)
            s.insert(it);
        return func(0, str, s, dp);
    }
};
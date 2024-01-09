class Solution
{
public:
    // --------------------------------------Backtracking

    // checking palindroem
    bool isPalindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }

    int solve(int i, string s1, string s2, string s)
    {
        // traversing the string, we check the two strings picked on the way whether they are
        // palindrome or not. If they are, we can return their product.
        if (i == s.size())
        {
            if (isPalindrome(s1) && isPalindrome(s2))
            {
                return (s1.size()) * (s2.size());
            }
            return 0;
        }

        // not take
        int not_take = solve(i + 1, s1, s2, s);
        // if take, either in s1 or in s2
        int take_s1 = solve(i + 1, s1 + s[i], s2, s);
        int take_s2 = solve(i + 1, s1, s2 + s[i], s);

        // return max length of all the options
        return max(not_take, max(take_s1, take_s2));
    }
    int maxProduct(string s)
    {
        int n = s.length();

        return solve(0, "", "", s);
    }
};
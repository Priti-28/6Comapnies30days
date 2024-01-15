class Solution
{
public:
    /*
    s= abcd
    t= cdef
    v = {2, 2, 2, 2}
    i = 0, cost = 2, (2> 3)No, maxlen = (INT_MIN, 0-0+1) = 1
    
    */
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();

        /// vector<int> v(n, 0);
        int v[n];

        for (int i = 0; i < n; i++)
            v[i] = abs(s[i] - t[i]);

        int cost = 0, start = 0, maxlen = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            cost = cost + v[i];
            while (cost > maxCost)
            {
                cost = cost - v[start++];
            }
            maxlen = max(maxlen, i - start + 1);
        }

        return maxlen;
    }
};
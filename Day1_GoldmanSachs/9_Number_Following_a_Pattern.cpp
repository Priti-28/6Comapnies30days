//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        // code here
        int n = s.size();
        stack<int> st;
        string ans = "";
        int count = 1;
        for (int i = 0; i <= n; i++)
        {
            st.push(count);
            count++;
            if (i == n || s[i] == 'I')
            {
                while (!st.empty())
                {
                    ans += st.top() + '0'; // to convert st.top element into string
                    st.pop();
                }
            }
        }
        return ans;
    }
};


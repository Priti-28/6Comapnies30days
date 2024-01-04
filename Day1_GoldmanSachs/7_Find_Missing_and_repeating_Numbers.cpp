//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int N)
    {
        // code here

        long long n = arr.size();

        long long Sn = ((long long)n * (long long)(n + 1)) / 2;                            // Sum of first n natural number
        long long S_Sn = ((long long)n * (long long)(n + 1) * (2 * (long long)n + 1)) / 6; // Sum of squares of first n natural number

        long long Sum = 0;   // Sum of all number of array
        long long S_Sum = 0; // Sum of square of all numbers of an array
        for (int i = 0; i < n; i++)
        {
            Sum = Sum + (long long)arr[i];
            S_Sum = S_Sum + ((long long)arr[i] * (long long)arr[i]);
        }

        long long diff = Sum - Sn;        // x - y (Array sum - N natural number sum)
        long long Sq_diff = S_Sum - S_Sn; // X2 - y2 (Array square sum - N natural number square sum)

        long long plus = Sq_diff / diff; // x + y

        long long x = (plus + diff) / 2;
        long long y = x - diff;

        return {(int)x, (int)y};
    }
};

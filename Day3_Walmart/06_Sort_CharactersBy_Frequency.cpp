class Solution
{
public:
    // Time Complexity: O(log(n)) For Construction and extraction from heap
    // Space :- O(n) For storing the frequency in hashmap.

    string frequencySort(string s)
    {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq; // {3, e}
        string ans;

        for (char it : s)
            m[it]++;

        // will be in descending order of frequency
        // {3, e}
        for (auto it : m)
            pq.push({it.second, it.first});

        while (!pq.empty())
        {
            pair<int, char> curr = pq.top();
            pq.pop();
            int freq = curr.first; // 3
            while (freq > 0)
            {
                ans.push_back(curr.second);
                freq--;
            }
        }

        return ans;
    }
};
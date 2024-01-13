class Solution
{
public:
    static bool cmp(pair<string, int> a, pair<string, int> b)
    {
        // if frequency are equal then return in decreasing order, otherwise return
        // abc , 4
        // def, 4
        if (a.second > b.second || (a.second == b.second && a.first < b.first))
            return true;
        return false;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        int n = words.size();

        /* First we will find the frequency of all the strings then we will keep track of the top
        k frequent strings with the help of priority queue */
        unordered_map<string, int> m;

        for (auto it : words)
            m[it]++; // pushing numbers with frequency

        vector<pair<string, int>> pq; // {abc, 4} { string , frequency}
        for (auto it = m.begin(); it != m.end(); it++)
            pq.push_back({it->first, it->second}); // pushing all element in priority queue with frequency

        sort(pq.begin(), pq.end(), cmp);

        vector<string> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(pq[i].first); // pushing first k elements in ans vector

        return ans;
    }
};
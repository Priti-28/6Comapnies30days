class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        map<string, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            string temp = s.substr(i, 10);
            if (m.find(temp) == m.end()) // not present in map
            {
                m.insert({temp, 1});
            }
            else if (m.find(temp) != m.end()) // present in map
            {
                m[temp]++;
            }
        }

        vector<string> v;
        for (auto it : m)
        {
            if (it.second > 1)
                v.push_back(it.first);
        }
        return v;
    }
};
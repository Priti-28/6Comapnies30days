
class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        int n = access_times.size();
        vector<string> v;
        map<string, vector<int>> m;
        for (auto it : access_times)
        {
            if (m.find(it[0]) != m.end())
            {
                m[it[0]].push_back({stoi(it[1])});
            }
            else
            {
                m.insert({it[0], {stoi(it[1])}});
            }
        }

        for (auto &it : m)
        {
            sort(it.second.begin(), it.second.end());
        }
        for (auto it : m)
        {
            int maxi = 0;
            int count_track = 1;
            int limit_track = 0;
            int siz = it.second.size();
            for (int i = 0; i < siz - 1; i++)
            {
                if ((limit_track + (it.second[i + 1] - it.second[i])) >= 100)
                {
                    maxi = max(maxi, count_track);
                    count_track = 1;
                    limit_track = 0;
                }
                if ((abs(it.second[i + 1] - it.second[i])) < 100 && limit_track < 100)
                {
                    if ((limit_track + (it.second[i + 1] - it.second[i])) < 100)
                    {
                        count_track++;
                        limit_track = limit_track + (it.second[i + 1] - it.second[i]);
                    }
                }
            }
            if (count_track >= 3 || maxi >= 3)
                v.push_back(it.first);
        }
        return v;
    }
};
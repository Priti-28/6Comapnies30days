class Solution
{
public:
    //-------------------------------Using Vector of Pair-----------------------------------------------

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<pair<int, vector<int>>> v;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int d = abs(rCenter - i) + abs(cCenter - j); // caculating distance between cells
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                v.push_back(make_pair(d, temp)); // {1, {0,1}} where 1 is the distance from cell(0,0) to (0,1)
            }
        }

        sort(v.begin(), v.end());

        vector<vector<int>> ans;
        for (int i = 0; i < v.size(); i++)
        {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
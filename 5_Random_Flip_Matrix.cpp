class Solution
{
    set<pair<int, int>> s;

private:
    int row;
    int col;

public:
    Solution(int m, int n)
    {
        row = m;
        col = n;
    }

    vector<int> flip()
    {
        int i = rand() % row;
        int j = rand() % col;
        if (s.find({i, j}) == s.end())
        {
            s.insert({i, j});
            return {i, j};
        }
        else
            return flip();
    }

    void reset()
    {
        s.clear();
    }
};


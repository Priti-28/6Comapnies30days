class Solution
{
public:
    bool isValid(int ind, vector<vector<int>> &special, vector<int> &needs)
    {
        for (int i = 0; i < needs.size(); i++)
        {
            if (needs[i] - special[ind][i] < 0)
                return false;
        }
        return true;
    }

    int solve(int ind, int n, vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        if (ind == special.size())
        {
            int total_sum = 0;
            for (int i = 0; i < needs.size(); i++)
            {
                total_sum += needs[i] * price[i];
            }
            return total_sum;
        }

        // not_pick
        int not_pick = 1e9, pick = 1e9;
        not_pick = solve(ind + 1, n, price, special, needs);

        // if we can pick
        if (isValid(ind, special, needs))
        {
            for (int i = 0; i < needs.size(); i++)
            {
                needs[i] = needs[i] - special[ind][i];
            }
            pick = special[ind][n] + solve(ind, n, price, special, needs);

            for (int i = 0; i < needs.size(); i++)
            {
                needs[i] = needs[i] + special[ind][i];
            }
        }

        return min(pick, not_pick);
    }
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int n = needs.size();
        return solve(0, n, price, special, needs);
    }
};
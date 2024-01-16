class Solution
{
public:
    // Here, This types of cases are invalid
    // [["X","X","X","X"],[".",".",".","X"],[".",".",".","X"]]

    int countBattleships(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X')
                {
                    // If there is 'X' in left or up of current cell,continue.
                    // Otherwise,  make battleship.
                    if ((i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X'))
                    {
                        continue;
                    }
                    else
                        ans++;
                }
            }
        }
        return ans;
    }
};
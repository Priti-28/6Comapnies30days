class Solution
{
public:
    string getHint(string secret, string guess)
    {
        vector<int> bulls(10, 0); // number can vary from 0 to 10
        vector<int> cows(10, 0);  // same reason

        int A = 0, B = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
                A++;
            else
            {
                // eg:- 1123
                //      0111
                // for i = 0, bulls[1]++, cows[0]++
                bulls[secret[i] - '0']++;
                cows[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < bulls.size(); i++)
        {
            B += min(bulls[i], cows[i]);
        }

        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};
class Solution
{
public:
    /*TC : O(2N + N*S)
     2N- for storing word in set s and counting valid encoding string,
    N*S- for erasing all suffixes of word, where S =  size of string

    SC: O(N) - for set
    */

    int minimumLengthEncoding(vector<string> &words)
    {

        // Declaring set and copying words in the set
        set<string> s(words.begin(), words.end());

        // Traversing in words and removing suffix from set
        /*
        it = time, i = 1, s.erase(ime) from set
                   i = 2, s.erase(me) from set
                   i = 3, s.erase(e) from set
        it = me,   i = 1, s.erase(e) from set
        it = bell  i = 1 , s.erase(ell) from set
                   i = 2, s.erase(ll) from set
                   i = 3, s.erase(l) fromset
        */
        for (auto &it : words)
        {
            for (int i = 1; i < it.size(); i++)
            {
                s.erase(it.substr(i));
            }
        }

        // Now set will contain unique words without any suffixes
        int ans = 0;
        for (auto it : s)
            ans += it.size() + 1;

        return ans;
    }
};
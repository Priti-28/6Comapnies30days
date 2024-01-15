class Solution
{
public:
    /*
    Approach:- Instead of checking every two people, let us group them by their age group,
                for that is what matters to check the conditions.
             - Eg: Age grp A: a people
                   Age grp B: b people
                   If A and B can be friends -> then no of friend requests = a * b
                   If say age grp C: c people -> and if people of age grp C can form friends
                                                 with themselves, then no of friend requests = c * (c - 1)

    Example:- [16,17,18]

            16->1, 17->1, 18->1
            Loop 1:-16 16(yes, {1*(1-1) = 0} ),
                    16 17(No),
                    16 18(No),
            Loop 2:-17 16(Yes, {1*(1-0) = 1}),
                    17 17(Yes, {1*(1-1) = 0}),
                    17 18(No)
            Loop 3:-18 16(no, Bcz of 1st reason)
                    18 17(Yes, {1*(1-0) = 1}),
                    18 18(Yes, {1*(1-1) = 0})

                    Final Ans:- 17 16 and 18 17

    Time: O(n)
    Space complexity: O(120)
            */

    bool isFriend(int x, int y)
    {
        bool cond1 = (y <= (x * 0.5) + 7);
        bool cond2 = (y > x);
        bool cond3 = (x < 100 && y > 100);

        return !(cond1 || cond2 || cond3); // If any of the conditionis true thrn return false
    }

    int numFriendRequests(vector<int> &ages)
    {
        int n = ages.size();
        unordered_map<int, int> m;

        for (int it : ages)
            m[it]++; // storing in map

        int ans = 0;

        for (auto it1 : m)
        {
            for (auto it2 : m)
            {
                if (isFriend(it1.first, it2.first))
                {
                    ans += it1.second * (it2.second - (it1.first == it2.first ? 1 : 0));
                    // if numbers are same gives 1 else 0
                }
            }
        }

        return ans;
    }
};
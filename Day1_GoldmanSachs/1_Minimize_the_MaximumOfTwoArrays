class Solution {
public:
    bool check(long long divi1, long long divi2, long long count1, long long count2, long long x)
    {
        long long A = x / divi1; // A = #(Total number) of numbers divisible by d1
        long long A_ = x - A;    // A' = # of numbers not divisible by d1
        long long B = x / divi2;  // B = # of numbers divisible by d2
        long long B_ = x - B;     // B' = # of numbers not divisible by d2
        long long AIB = x / lcm(divi1, divi2); // A Intersection B of  numbers=                                       // divisible by BOTH d1 AND d2
        long long AUB = A + B - AIB;   // A Union B = # of numbers divisible by EITHER d1 OR d2
        long long A_UB_ = x - AUB; // (A' Union B') = (A Intersection B)' = # of numbers not divisible by NEITHER OF THEM


        // A_required_numbers = # of numbers needed to have atleast u1 numbers of set1, these numbers
        // don't include (A' Union B')
        long long A_required_numbers = (A_ - A_UB_ >= count1) ? 0 : (count1 -( A_ - A_UB_));

        // B_required_numbers = # of numbers needed to have atleast u2 numbers of set2, these numbers
        // don't include (A' Union B')
        long long B_required_numbers = (B_ - A_UB_ >= count2) ? 0 : (count2 -( B_ - A_UB_));

        return (A_UB_ >=A_required_numbers + B_required_numbers);

    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long low = 1, high = 1e17; // search space
        while(high > low + 1)
        {
             long long mid = (low + high) >> 1;
            if(check(divisor1, divisor2, uniqueCnt1,uniqueCnt2, mid)) high = mid;
            else low = mid;
        }
        return high;
    }
};
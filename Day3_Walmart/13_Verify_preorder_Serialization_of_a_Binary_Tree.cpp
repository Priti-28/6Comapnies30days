class Solution
{
public:
    /*
    Approach:-
     -> vacancy will be counted for every node
        where, vacancy means the number of more nodes that current node can generate
        i.e Node A creates 2 nodes:- left and right child
        i.e Null Node creates 0 nodes

     -> Initially root Node occupy only 1 vacancy so vacancy is iitializes as 1

     ->
    */
    bool isValidSerialization(string preorder)
    {

        int vacancy = 1;
        for (int i = 0; i < preorder.size(); i++)
        {
            if (preorder[i] == ',')
                continue; // if we encounter a , then do nothing
            // reduce the vacancy as the current value eats up a vacancy
            vacancy--;

            // increment the iterator till we encounter a nmbr because node
            // value can be of more than one digit
            while (i < preorder.size() && preorder[i] >= '0' && preorder[i] <= '9' && preorder[i] != ',')
                i++;

            // if here we have an invalid vacancy then preorder is not correct
            // i.e tree cannot be formed out of it
            if (vacancy < 0)
                return false;

            // if the current value is not # then it will contribute 2 vacancy
            //  of left and right child hence increase vacancy
            if (preorder[i] != '#')
                vacancy += 2; // there is a number then 2 child
        }
        if (vacancy == 0)
            return true; // Vacancy = 0  then everything is correct
        return false;
        // if vacancy is still left but string is finished then we will return false
    }
};
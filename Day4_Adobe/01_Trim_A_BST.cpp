
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return NULL;

        // checking root's val should be equal or inside the low and high.
        if (root->val >= low && root->val <= high)
        {
            // Update left and right bcz may be left node is out of range ,
            // so we have to return new left node
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }

        // if root's val is smaller. eg:- root's val is 0, Our range is [1-4]
        // then no need of going to left bcz it is BST. Eveything on left is smaller
        // So go only right side
        else if (root->val < low)
            return trimBST(root->right, low, high);

        // if root'val is greater than high. eg:- root's val is 5. Range:-[1-4]
        // then no use of going right , as all value are greater than 5.
        // So goonly left side
        else if (root->val > high)
            return trimBST(root->left, low, high);

        return root;
    }
};
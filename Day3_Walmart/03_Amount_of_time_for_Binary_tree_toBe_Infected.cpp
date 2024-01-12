
class Solution
{
public:
    //----------------BFS ----------------------------

    map<int, vector<int>> m;
    int totalnode = 0;
    map<int, bool> vis; // not making vector<int> vis bcz all nodes are not insequential order

    // Strong all nodes in form of map like:- {1, {5, 3}}
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        vis[root->val] = false;

        if (root->left != NULL)
        {
            m[root->left->val].push_back(root->val);
            m[root->val].push_back(root->left->val);
            dfs(root->left);
        }

        if (root->right != NULL)
        {
            m[root->right->val].push_back(root->val);
            m[root->val].push_back(root->right->val);
            dfs(root->right);
        }
        return;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        // Keeping record of all its adjacent node
        dfs(root);

        int ans = 0;

        queue<pair<int, int>> q;
        q.push({start, 0});
        vis[start] = true;

        while (!q.empty())
        {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            vis[node] = true;
            ans = max(ans, time);

            for (auto it : m[node])
            {
                if (vis[it] == false)
                    q.push({it, time + 1});
            }
        }
        return ans;
    }
};
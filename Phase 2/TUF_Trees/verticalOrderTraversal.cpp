#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> todos;

    todos.push({root, {0, 0}});
    while (!todos.empty())
    {
        auto p = todos.front();
        todos.pop();
        TreeNode *temp = p.first;
        int ver = p.second.first;
        int lev = p.second.second;

        nodes[ver][lev].insert(temp->val);

        if (temp->left)
        {
            todos.push({temp->left, {p.second.first - 1, p.second.second + 1}});
        }
        if (temp->right)
        {
            todos.push({temp->right, {p.second.first + 1, p.second.second + 1}});
        }
    }
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            for (auto r : q.second)
            {
                col.push_back(r);
            }
        }
        ans.push_back(col);
    }
    return ans;
}
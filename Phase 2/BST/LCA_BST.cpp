#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        TreeNode *node = root;
        while (true)
        {
            if (node->val > p->val && node->val > q->val)
            {
                node = node->left;
                continue;
            }
            else if (node->val < p->val && node->val < q->val)
            {
                node = node->right;
                continue;
            }
            else
            {
                break;
            }
        }
        return node;
    }
};
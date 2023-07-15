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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *node = root;
    TreeNode *newNode = new TreeNode();
    if (root == NULL)
    {
        newNode->val = val;
        root = newNode;
        return root;
    }

    while (node)
    {
        if (node->val > val)
        {
            if (node->left == NULL)
            {

                node->left = newNode;
                newNode->val = val;
                break;
            }
            else
                node = node->left;
        }
        else
        {
            if (node->right == NULL)
            {

                node->right = newNode;
                newNode->val = val;
                break;
            }
            else
                node = node->right;
        }
    }

    return root;
}

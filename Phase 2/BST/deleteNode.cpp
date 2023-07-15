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

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->val == key)
    {
        return helper(root);
    }

    TreeNode *node = root;

    while (node)
    {
        if (key < node->val)
        {
            if (node->left && node->left->val == key)
            {
                node->left = helper(node->left);
                break;
            }
            else
            {
                node = node->left;
            }
        }
        else if (key > node->val)
        {
            if (node->right && node->right->val == key)
            {
                node->right = helper(node->right);
                break;
            }
            else
            {
                node = node->right;
            }
        }
    }
    return root;
}

TreeNode *helper(TreeNode *node)
{
    if (!node->left)
        return node->right;

    if (!node->right)
        return node->left;

    TreeNode *rightChild = node->right;
    TreeNode *leftRight = findLeftRight(node->left);

    leftRight->right = rightChild;
    return node->left;
}

TreeNode *findLeftRight(TreeNode *node)
{
    if (node->right == NULL)
        return node;

    return findLeftRight(node->right);
}

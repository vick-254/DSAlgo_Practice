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

class BSTIterator
{
private:
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *node = myStack.top();
        myStack.pop();
        pushAll(node->right);
        return node->val;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

    void pushAll(TreeNode *node)
    {
        while (node)
        {
            myStack.push(node);
            node = node->left;
        }
    }
};
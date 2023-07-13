#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void helper(Node *node, int level, vector<int> &ans)
{
    if (node == NULL)
        return;

    if (level == ans.size())
        ans.push_back(node->data);

    helper(node->left, level + 1, ans);
    helper(node->right, level + 1, ans);
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    helper(root, 0, ans);
    return ans;
}
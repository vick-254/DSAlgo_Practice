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
void helper(TreeNode *root, int k, int &cnt, int &ans)
{
    if (root == NULL)
        return;

    helper(root->left, k, cnt, ans);
    if (k == cnt)
    {
        ans = root->val;
        cnt = k + 1;
        return;
    }
    else
        cnt++;
    helper(root->right, k, cnt, ans);
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = 0;
    int cnt = 1;
    helper(root, k, cnt, ans);
    return ans;
}
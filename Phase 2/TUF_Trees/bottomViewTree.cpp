#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *temp = p.first;
        int level = p.second;

        mpp[level] = temp->data;

        if (temp->left)
        {
            q.push({temp->left, p.second - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, p.second + 1});
        }
    }
    for (auto i : mpp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
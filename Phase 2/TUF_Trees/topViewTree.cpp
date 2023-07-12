
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mpp;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {

        auto p = q.front();
        q.pop();

        Node *node = p.first;
        if (mpp.find(p.second) == mpp.end())
            mpp[p.second] = node->data;

        if (node->left)
            q.push({node->left, p.second - 1});

        if (node->right)
            q.push({node->right, p.second + 1});
    }

    for (auto i : mpp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
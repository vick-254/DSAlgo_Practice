#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int isSumProperty(Node *root)
{
    if (root == NULL)
        return 1;

    if (!root->left && !root->right)
        return 1;

    // if(!root->left && root->right){
    //     if(root->right->data == root->data) return 1;
    //     else return 0;
    // }

    int sum = 0;
    if (root->left)
        sum += root->left->data;

    if (root->right)
        sum += root->right->data;

    // if(root->left && !root->right){
    //     if(root->left->data == root->data) return 1;
    //     else return 0;
    // }

    int left = isSumProperty(root->left);
    int right = isSumProperty(root->right);

    if (left == 1 && right == 1 && sum == root->data)
        return 1;
    else
        return 0;
}
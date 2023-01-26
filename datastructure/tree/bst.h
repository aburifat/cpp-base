#ifndef BST_NODE_H
#define BST_NODE_H

#include "../../algorithm/utils/max.h"

class bst_node
{
public:
    int key, size, height, frequency;
    bst_node *left;
    bst_node *right;
    bst_node(int key)
    {
        this->key = key;
        this->size = this->height = this->frequency = 1;
        this->left = this->right = nullptr;
    }
};

int bst_size(bst_node *root)
{
    return (root == nullptr) ? 0 : root->size;
}

int bst_height(bst_node *root)
{
    return (root == nullptr) ? 0 : root->height;
}

int bst_frequency(bst_node *root)
{
    return (root == nullptr) ? 0 : root->frequency;
}

int bst_balance_score(bst_node *root)
{
    return (root == nullptr) ? 0 : bst_height(root->left) - bst_height(root->right);
}

void bst_update_size_height(bst_node *root)
{
    bst_update_size(root);
    bst_update_height(root);
}

void bst_update_size(bst_node *root)
{
    if (root != nullptr)
        root->size = root->frequency + bst_size(root->left) + bst_size(root->right);
}

void bst_update_height(bst_node *root)
{
    if (root != nullptr)
        root->height = 1 + max(bst_height(root->left), bst_height(root->right));
}

bst_node *bst_min(bst_node *root)
{
    if (root == nullptr)
        return root;
    bst_node *curr = root;
    while (curr->left != nullptr)
        curr = curr->left;
    return curr;
}

bst_node *bst_max(bst_node *root)
{
    if (root == nullptr)
        return root;
    bst_node *curr = root;
    while (curr->right != nullptr)
        curr = curr->right;
    return curr;
}

bst_node *bst_insert(bst_node *root, int key)
{
    if (root == nullptr)
        return new bst_node(key);
    if (root->key == key)
        root->frequency++;

    else if (key < root->key)
        root->left = bst_insert(root->left, key);
    else
        root->right = bst_insert(root->right, key);
    bst_update_size_height(root);
    return root;
}

bst_node *bst_delete(bst_node *root, int key)
{
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = bst_delete(root->left, key);
    else if (key > root->key)
        root->right = bst_delete(root->right, key);
    else if ((bst_frequency(root)) > 1)
    {
        root->frequency--;
    }
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            bst_node *tmp = (root->left != nullptr) ? root->left : root->right;
            if (tmp == nullptr)
            {
                tmp = root;
                root = nullptr;
            }
            else
                *root = *tmp;
            delete tmp;
        }
        else
        {
            bst_node *tmp = bst_min(root->right);
            root->key = tmp->key;
            root->right = bst_delete(root->right, tmp->key);
        }
    }
    bst_update_size_height(root);
    return root;
}

#endif
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "bst.h"
#include "bst_rotation.h"

struct avl_tree
{
    bst_node *root;
    avl_tree() : root(nullptr) {}
};

bst_node *avl_insert(bst_node *root, int key)
{
    root = bst_insert(root, key);
    return avl_balance(root);
}

bst_node *avl_delete(bst_node *root, int key)
{
    root = bst_delete(root, key);
    return avl_balance(root);
}

bst_node *avl_update(bst_node *root, int old_key, int new_key)
{
    root = avl_delete(root, old_key);
    return avl_insert(root, new_key);
}

bst_node *avl_balance(bst_node *root)
{
    bst_update_size_height(root);
    int balance_score = bst_balance_score(root);
    if (balance_score > 1)
    {
        if (bst_balance_score(root->left) < 0)
            bst_left_rotate(root->left);
        return bst_right_rotate(root);
    }
    else if (balance_score < -1)
    {
        if (bst_balance_score(root->right) > 0)
            bst_right_rotate(root->right);
        return bst_left_rotate(root);
    }
}

#endif
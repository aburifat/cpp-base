#ifndef BST_ROTATION_H
#define BST_ROTATION_H

#include "../../algorithm/utils/max.h"
#include "bst.h"

bst_node *bst_right_rotate(bst_node *root)
{
    bst_node *newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    bst_update_size_height(root);
    bst_update_size_height(newroot);
    return newroot;
}

bst_node *bst_left_rotate(bst_node *root)
{
    bst_node *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    bst_update_size_height(root);
    bst_update_size_height(newroot);
    return newroot;
}

#endif
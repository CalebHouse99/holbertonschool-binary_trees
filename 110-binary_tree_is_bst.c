#include <limits.h>
#include "binary_trees.h"
#include <stddef.h>

int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    if (tree->n < min || tree->n > max)
        return 0;

    return is_bst_helper(tree->left, min, tree->n - 1) &&
           is_bst_helper(tree->right, tree->n + 1, max);
}

int binary_tree_is_bst(const binary_tree_t *tree)
{
    return is_bst_helper(tree, INT_MIN, INT_MAX);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct binary_tree_s
{
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    if (tree->value < min || tree->value > max)
        return 0;

    return is_bst_helper(tree->left, min, tree->value - 1) &&
           is_bst_helper(tree->right, tree->value + 1, max);
}

int binary_tree_is_bst(const binary_tree_t *tree)
{
    return is_bst_helper(tree, INT_MIN, INT_MAX);
}

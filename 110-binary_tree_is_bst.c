#include <limits.h>
#include "binary_trees.h"

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

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

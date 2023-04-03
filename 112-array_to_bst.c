#include "binary_trees.h"
#include <stddef.h>

/**
 * array_to_bst - Converts an array to a binary search tree
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    size_t i;
    bst_t *root = NULL;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        bst_insert(&root, array[i]);
    }

    return (root);
}

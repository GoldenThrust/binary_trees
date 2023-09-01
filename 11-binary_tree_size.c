#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 1;

	if (tree)
	{
		tree_size += binary_tree_size(tree->left);
		tree_size += binary_tree_size(tree->right);
	}
	else
		return (0);

	return (tree_size);
}

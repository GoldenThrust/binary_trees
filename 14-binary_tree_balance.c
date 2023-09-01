#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: computed num
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_t = 0, right_t = 0;

	if (tree == NULL)
		return (0);

	left_t = tree->left ? binary_tree_height(tree->left) + 1 : 1;
	right_t = tree->right ? binary_tree_height(tree->right) + 1 : 1;

	return (left_t > right_t ? left_t : right_t);
}

#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t height = binary_tree_height(tree);

	return (binary_tree_is_perfect_recursive(tree, 0, height));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to check.
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_t = 0, right_t = 0;

	if (tree == NULL)
		return (0);

	left_t = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right_t = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (left_t > right_t ? left_t : right_t);
}

/**
 * binary_tree_is_perfect_recursive - checks whether a binary tree is perfect
 * by comparing the depth of nodes with the given height of the tree.
 * @tree: Pointer to the root node of the tree to check.
 * @depth: Current depth of the node being checked.
 * @height: Height of the binary tree.
 *
 * Return: 1 if the subtree rooted at tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree, size_t depth,
size_t height)
{
	if (tree == NULL)
		return (depth == height);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == height);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_perfect_recursive(tree->left, depth + 1, height) &&
		   binary_tree_is_perfect_recursive(tree->right, depth + 1, height));
}

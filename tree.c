/*
 * Author: Bassel Ashi for CSCB09
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

/**
 *  A helper function that allocates a new tree node.
 *
 *  @param value The entry's value. It represents either an attribute or a filename.
 *  @return A pointer to the newly allocated node.
 *  (for now it returns NULL, so the compiler does not complain)
 */
struct TreeNode *allocate_node(const char *value)
{
	struct TreeNode *new = malloc(sizeof(struct TreeNode));

	if (new == NULL)
	{
		fprintf(stderr, "An error has occurred while allocating a node!");
		return NULL;
	}

	new->child = NULL;
	new->sibling = NULL;
	new->value = malloc(sizeof(value));
	strcpy(new->value, value);

	return new;
}

struct TreeNode *tree_insert_helper(struct TreeNode *root, struct TreeNode *new, char **values, int level)
{
	// Level 1 -> color
	// Level 2 -> shape
	// Level 3 -> texture
	// Level 4 -> value
	if (root == NULL && level == 1)
	{
		// Base case of level #1
		struct TreeNode *colourNode = allocate_node(values[1]);
		colourNode->child = tree_insert_helper(colourNode->child, new, values, level + 1);
		return colourNode;
	}
	else if (root == NULL && level == 2)
	{
		// Base case of level #2
		struct TreeNode *shapeNode = allocate_node(values[2]);
		shapeNode->child = tree_insert_helper(shapeNode->child, new, values, level + 1);
		return shapeNode;
	}
	else if (root == NULL && level == 3)
	{
		// Base case of level #3
		struct TreeNode *textureNode = allocate_node(values[3]);
		textureNode->child = tree_insert_helper(textureNode->child, new, values, level + 1);
		return textureNode;
	}
	else if (root == NULL && level == 4)
	{
		// Base case of level #4
		return new;
	}

	if (level == 0)
	{
		// Still at root
		root->child = tree_insert_helper(root->child, new, values, level + 1);
	}
	else if (level == 1)
	{
		if (strcmp(values[1], root->value) == 0)
		{
			// If current node is the same
			root->child = tree_insert_helper(root->child, new, values, level + 1);
		}
		else
		{
			// If current node is not the same
			root->sibling = tree_insert_helper(root->sibling, new, values, level);
		}
	}
	else if (level == 2)
	{
		if (strcmp(values[2], root->value) == 0)
		{
			// If current node is the same
			root->child = tree_insert_helper(root->child, new, values, level + 1);
		}
		else
		{
			// If current node is not the same
			root->sibling = tree_insert_helper(root->sibling, new, values, level);
		}
	}
	else if (level == 3)
	{
		if (strcmp(values[3], root->value) == 0)
		{
			// If current node is the same
			root->child = tree_insert_helper(root->child, new, values, level + 1);
		}
		else
		{
			// If current node is not the same
			root->sibling = tree_insert_helper(root->sibling, new, values, level);
		}
	}
	else if (level == 4)
	{
		// Current node is taken, make it sibling
		root->sibling = tree_insert_helper(root->sibling, new, values, level);
	}

	return root;
}

/**
 *  Insert a new image to a tree
 *
 *  @param tree A pointer to the root of the tree.
 *  @param values An array, whose first three members are the attribute values for 
 *                the image and the last one is the filename
 */
void tree_insert(struct TreeNode *root, char **values)
{
	struct TreeNode *new = allocate_node(values[4]);
	if (new == NULL)
		return;

	root = tree_insert_helper(root, new, values, 0);
}

void tree_search_helper(struct TreeNode *root, char **values, int level)
{
	if (root == NULL && level != 4)
	{
		printf("(NULL)\n");
		return;
	}

	if (level == 0)
	{
		tree_search_helper(root->child, values, level + 1);
	}
	else if (level == 1)
	{
		if (strcmp(root->value, values[1]) == 0)
		{
			tree_search_helper(root->child, values, level + 1);
		}
		else
		{
			tree_search_helper(root->sibling, values, level);
		}
	}
	else if (level == 2)
	{
		if (strcmp(root->value, values[2]) == 0)
		{
			tree_search_helper(root->child, values, level + 1);
		}
		else
		{
			tree_search_helper(root->sibling, values, level);
		}
	}
	else if (level == 3)
	{
		if (strcmp(root->value, values[3]) == 0)
		{
			tree_search_helper(root->child, values, level + 1);
		}
		else
		{
			tree_search_helper(root->sibling, values, level);
		}
	}
	else if (level == 4)
	{
		if (root != NULL)
		{
			printf("%s ", root->value);
			tree_search_helper(root->sibling, values, level);
		}
	}
}

/**
 *  Searches a tree to print all files with matching attribute values.
 *
 *  @param tree A pointer to the root of the tree.
 *  @param values An array of attribute values
 */
void tree_search(const struct TreeNode *root, char **values)
{
	struct TreeNode *tr = (struct TreeNode *)root;
	tree_search_helper(tr, values, 0);
	printf("\n");
}

void tree_print_helper(struct TreeNode *root, int level)
{
	if (root != NULL)
	{
		if (level == 0)
		{
			tree_print_helper(root->child, level + 1);
		}
		else if (level == 1 || level == 2 || level == 3)
		{
			tree_print_helper(root->child, level + 1);
			tree_print_helper(root->sibling, level);
		}
		else if (level == 4)
		{
			//printf("%s %s %s %s", root->value);
			tree_print_helper(root->sibling, level);
		}
	}
}

/**
 *  Prints a complete tree to the standard output.
 *
 *  @param tree A pointer to the root of the tree.
 */
void tree_print(const struct TreeNode *tree)
{
	if (tree->child == NULL)
	{
		printf("(NULL)\n");
		return;
	}

	struct TreeNode *tr = (struct TreeNode *)tree;
	tree_print_helper(tr, 0);
	printf("\n");
}

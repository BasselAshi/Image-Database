/*
 * Author: Bassel Ashi for CSCB09
 */

#ifndef _TREE_H
#define _TREE_H

#include "utils.h"


struct TreeNode {
	char *value;

        struct TreeNode *sibling;
        struct TreeNode *child;
};

struct TreeNode *tree_insert_helper(struct TreeNode *, struct TreeNode *, char **, int);
void tree_insert(struct TreeNode *, char **);
void tree_search_helper(struct TreeNode *, char **, int);
void tree_search(const struct TreeNode *, char **);
void tree_print(const struct TreeNode *);

#endif /* _TREE_H */

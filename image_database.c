/*
 * Author: Bassel Ashi for CSCB09
 */

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "utils.h"

void printError()
{
    fprintf(stderr, "Invalid command.\n");
}

int main(void)
{

    // char array to hold a line of input
    char buf[BUFFER_SIZE] = {'\0'};

    // char* array to hold the pointers to tokens
    char *args[INPUT_ARG_MAX_NUM];
    args[0] = malloc(BUFFER_SIZE);
    args[1] = malloc(BUFFER_SIZE);
    args[2] = malloc(BUFFER_SIZE);
    args[3] = malloc(BUFFER_SIZE);
    args[4] = malloc(BUFFER_SIZE);
    int numArgs;

    // the root of the tree
    struct TreeNode root;
        root.value = "";
        root.child = NULL;
        root.sibling = NULL;

	struct TreeNode *root_ptr = &root;

    // Add your code below:
    while (fgets(buf, BUFFER_SIZE, stdin) != NULL)
    {
        numArgs = tokenize(buf, args);
        
        if (args[0][0] == 'p' && args[0][1] == '\0' && numArgs == 1) {
            // Print
            tree_print(root_ptr);
        } else if (args[0][0] == 'q' && args[0][1] == '\0' && numArgs == 4) {
            // Query
            tree_search(root_ptr, args);
        } else if (args[0][0] == 'i' && args[0][1] == '\0' && numArgs == 5) {
            // Insert
            tree_insert(root_ptr, args);
        } else {
            printError();
        }
    }

    return 0;
}

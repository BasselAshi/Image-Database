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
        /*struct TreeNode root;
        root.value = "";
        root.child = NULL;
        root.sibling = NULL;

	struct TreeNode *root_ptr = &root;*/

        // Add your code below:
        while (fgets(buf, BUFFER_SIZE, stdin) != NULL)
        {
                numArgs = tokenize(buf, args);
                printf("%d", numArgs);
        }

        if (numArgs == 0) printError;
                return 0;
}

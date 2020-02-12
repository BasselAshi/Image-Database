/*
 * Author: Bassel Ashi for CSCB09
 */

#include <stdio.h>
#include <string.h>

#include "utils.h"

/*
 * Tokenize the string stored in cmd based on DELIMITERS as separators.
 * Return the number of tokens, and store pointers to them in cmd_argv.
 */
int tokenize(char *cmd, char **cmd_argv)
{
        // returning 0 for now, so the compiler does not complain
        char *token = strtok(cmd, DELIMITERS);
        int numTokens = 0;

        while (token != NULL)
        {
                if (numTokens < INPUT_ARG_MAX_NUM)
                {
                        strcpy(cmd_argv[numTokens], token);
                        printf("%s\n", cmd_argv[numTokens]);
                }
                numTokens++;
                token = strtok(NULL, DELIMITERS);
        }
        return numTokens;
}

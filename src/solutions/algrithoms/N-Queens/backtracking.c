/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>

void solveNQueensCore(int n, int level, int* col, int* slash, int* bSlash, int* track, int* returnSize, char**** resP);

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int col[n], slash[n * 2 - 1], bSlash[n * 2 - 1], track[n];
    memset(col, 0, n * sizeof(int));
    memset(slash, 0, (n * 2 - 1) * sizeof(int));
    memset(bSlash, 0, (n * 2 - 1) * sizeof(int));
    memset(track, 0, n * sizeof(int));
    
    *returnSize = 0;
    char ****resP = (char****)malloc(sizeof(char***));
    char ***res;
    resP[0] = res;
    solveNQueensCore(n, 0, col, slash, bSlash, track, returnSize, resP);

    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return *resP;
}

void solveNQueensCore(int n, int level, int* col, int* slash, int* bSlash, int* track, int* returnSize, char**** resP) {
    if (level == n) {
        *resP = (char***)realloc(*resP, (*returnSize + 1) * sizeof(char**));
        (*resP)[*returnSize] = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            (*resP)[*returnSize][i] = (char*)malloc((n + 1) * sizeof(char));
            for (int j = 0; j < n; j++) {
                (*resP)[*returnSize][i][j] = '.';
            }
            (*resP)[*returnSize][i][track[i]] = 'Q';
            (*resP)[*returnSize][i][n] = '\0';
        }
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (col[i] || slash[level + i] || bSlash[level - i + n - 1]) {
            continue;
        }
        col[i] = 1;
        slash[level + i] = 1;
        bSlash[level - i + n - 1] = 1;
        track[level] = i;
        solveNQueensCore(n, level + 1, col, slash, bSlash, track, returnSize, resP);
        col[i] = 0;
        slash[level + i] = 0;
        bSlash[level - i + n - 1] = 0;
        track[level] = 0;
    }
}
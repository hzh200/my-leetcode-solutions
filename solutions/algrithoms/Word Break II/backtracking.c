/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>

void backtrack(char *s, char **wordDict, int wordDictSize, int* returnSize, char*** resP, char*** tmpP, int tmpSize);

char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize) {
    *returnSize = 0;
    char ***resP = (char***)malloc(sizeof(char**));
    char **res;
    resP[0] = res;
    char ***tmpP = (char***)malloc(sizeof(char**));
    char **tmp;
    tmpP[0] = tmp;
    backtrack(s, wordDict, wordDictSize, returnSize, resP, tmpP, 0);
    return *resP;
}

void backtrack(char *s, char **wordDict, int wordDictSize, int* returnSize, char*** resP, char*** tmpP, int tmpSize) {
    if (!*(s)) {
        (*returnSize)++;
        *resP = realloc(*resP, *returnSize * sizeof(char*));
        char *str = (char*)malloc(sizeof(char));
        int len = 0;
        for (int i = 0; i < tmpSize; i++) {
            char* tmpWord = (*tmpP)[i];
            str = realloc(str, (len + strlen(tmpWord) + 1) * sizeof(char));
            strcpy(str + len, tmpWord);
            len += (strlen(tmpWord) + 1);
            str[len - 1] = ' ';
        }
        str[len - 1] = '\0';
        (*resP)[*returnSize - 1] = str;
        return;
    }
    for (int i = 0; i < wordDictSize; i++) {
        int wordLen = strlen(wordDict[i]);
        if (strncmp(s, wordDict[i], wordLen) == 0) {
            (*tmpP) = realloc((*tmpP), (tmpSize + 1) * sizeof(char*));
            (*tmpP)[tmpSize] = (char*)malloc((wordLen + 1) * sizeof(char));
            strcpy((*tmpP)[tmpSize], wordDict[i]);
            (*tmpP)[tmpSize][wordLen] = '\0';
            backtrack(s + wordLen, wordDict, wordDictSize, returnSize, resP, tmpP, tmpSize + 1);
        }
    }
}
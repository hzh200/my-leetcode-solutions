char * mergeAlternately(char * word1, char * word2) {
    int len = strlen(word1) + strlen(word2);
    char* head = (char*)malloc((len + 1) * sizeof(char));
    char* res = head;
    while (*word1 && *word2) {
        *res++ = *word1++;
        *res++ = *word2++;
    }
    *word1 ? strcpy(res, word1) : strcpy(res, word2);
    head[len] = '\0';
    return head;
}
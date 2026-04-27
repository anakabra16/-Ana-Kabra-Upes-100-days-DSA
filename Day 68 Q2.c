#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 505
#define MAX_LEN 105

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    char words[MAX_WORDS][MAX_LEN];
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    int adj[26][26] = {0};
    int inDegree[26] = {0};
    int present[26] = {0};

    // Mark all characters present in the dictionary
    for (int i = 0; i < N; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build the graph by comparing adjacent words
    for (int i = 0; i < N - 1; i++) {
        char *word1 = words[i];
        char *word2 = words[i+1];
        int len1 = strlen(word1);
        int len2 = strlen(word2);
        int minLen = len1 < len2 ? len1 : len2;
        int j = 0;

        while (j < minLen && word1[j] == word2[j]) {
            j++;
        }

        if (j < minLen) {
            int u = word1[j] - 'a';
            int v = word2[j] - 'a';
            // Only add edge if it doesn't exist to avoid duplicate inDegree increments
            if (!adj[u][v]) {
                adj[u][v] = 1;
                inDegree[v]++;
            }
        } else {
            // If all characters matched but word1 is longer, word2 is a prefix of word1.
            // This is an invalid dictionary order according to standard lexicographical rules.
            if (len1 > len2) {
                printf("\"\"\n"); // Output empty string for invalid
                return 0;
            }
        }
    }

    // Kahn's Algorithm (Topological Sort)
    int queue[26];
    int front = 0, rear = 0;
    
    int uniqueChars = 0;
    for (int i = 0; i < 26; i++) {
        if (present[i]) {
            uniqueChars++;
            if (inDegree[i] == 0) {
                queue[rear++] = i;
            }
        }
    }

    char result[27];
    int count = 0;

    while (front < rear) {
        int u = queue[front++];
        result[count++] = u + 'a';

        for (int v = 0; v < 26; v++) {
            if (adj[u][v]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }
    result[count] = '\0';

    // If topological sort includes all unique characters, it's valid
    if (count == uniqueChars) {
        printf("%s\n", result);
    } else {
        printf("\"\"\n"); // Cycle detected, return empty string
    }

    return 0;
}

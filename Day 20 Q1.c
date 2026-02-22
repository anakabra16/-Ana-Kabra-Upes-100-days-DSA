#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 200003

typedef struct Node {
    long long key;
    long long count;
    struct Node* next;
} Node;

Node* table[TABLE_SIZE];

unsigned int hash(long long key) {
    key ^= (key >> 33);
    key *= 0xff51afd7ed558ccdULL;
    key ^= (key >> 33);
    return (unsigned int)(key % TABLE_SIZE);
}

long long getCount(long long key) {
    unsigned int h = hash(key);
    Node* curr = table[h];
    while (curr) {
        if (curr->key == key) return curr->count;
        curr = curr->next;
    }
    return 0;
}

void addKey(long long key) {
    unsigned int h = hash(key);
    Node* curr = table[h];
    while (curr) {
        if (curr->key == key) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->count = 1;
    node->next = table[h];
    table[h] = node;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    long long prefix = 0, result = 0;
    addKey(0);

    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        result += getCount(prefix);
        addKey(prefix);
    }

    printf("%lld", result);
    return 0;
}

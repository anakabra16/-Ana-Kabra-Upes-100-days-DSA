#include <stdio.h>
#include <stdlib.h>

#define SIZE 200003

typedef struct Node {
    long long key;
    long long count;
    struct Node *next;
} Node;

Node* table[SIZE];

unsigned int hash(long long key) {
    key ^= (key >> 33);
    key *= 0xff51afd7ed558ccdULL;
    key ^= (key >> 33);
    return (unsigned int)(key % SIZE);
}

long long get(long long key) {
    unsigned int h = hash(key);
    Node *cur = table[h];
    while (cur) {
        if (cur->key == key) return cur->count;
        cur = cur->next;
    }
    return 0;
}

void put(long long key) {
    unsigned int h = hash(key);
    Node *cur = table[h];
    while (cur) {
        if (cur->key == key) {
            cur->count++;
            return;
        }
        cur = cur->next;
    }
    Node *node = (Node*)malloc(sizeof(Node));
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

    long long prefix = 0, ans = 0;
    put(0);

    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        ans += get(prefix);
        put(prefix);
    }

    printf("%lld", ans);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int n1, int* nums2, int n2, int* returnSize) {
    int freq[1001] = {0};

    for (int i = 0; i < n1; i++) {
        freq[nums1[i]]++;
    }

    int* result = (int*)malloc(sizeof(int) * (n1 < n2 ? n1 : n2));
    int k = 0;

    for (int i = 0; i < n2; i++) {
        if (freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    *returnSize = k;
    return result;
}

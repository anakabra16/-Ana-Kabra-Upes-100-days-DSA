#include <stdlib.h>

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    int offset = 10000;
    int freq[20001] = {0};

    // count frequencies
    for(int i=0;i<numsSize;i++)
        freq[nums[i] + offset]++;

    // buckets
    int **bucket = (int**)malloc((numsSize+1)*sizeof(int*));
    int bucketSize[numsSize+1];

    for(int i=0;i<=numsSize;i++){
        bucket[i] = (int*)malloc(numsSize*sizeof(int));
        bucketSize[i] = 0;
    }

    // place numbers into buckets
    for(int i=0;i<20001;i++){
        if(freq[i] > 0){
            int f = freq[i];
            bucket[f][bucketSize[f]++] = i - offset;
        }
    }

    int *result = (int*)malloc(sizeof(int)*k);
    int idx = 0;

    // collect k most frequent
    for(int i=numsSize;i>=0 && idx<k;i--){
        for(int j=0;j<bucketSize[i] && idx<k;j++){
            result[idx++] = bucket[i][j];
        }
    }

    *returnSize = k;
    return result;
}
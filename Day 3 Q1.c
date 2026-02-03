#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];

    // input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // input key
    scanf("%d", &k);

    int comparisons = 0;
    int found = 0;

    for(int i = 0; i < n; i++) {
        comparisons++;           // one comparison
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;               // stop searching
        }
    }

    if(found == 0) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comparisons);

    return 0;
}

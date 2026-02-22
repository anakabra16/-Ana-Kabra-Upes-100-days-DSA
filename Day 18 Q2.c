#include <stdio.h>

void productExceptSelf(int nums[], int n, int result[]) {
    int left = 1;
    for (int i = 0; i < n; i++) {
        result[i] = left;
        left *= nums[i];
    }

    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= right;
        right *= nums[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n], result[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    productExceptSelf(nums, n, result);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}

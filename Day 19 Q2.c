#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int total = nums[0];
    int currMax = nums[0], maxSum = nums[0];
    int currMin = nums[0], minSum = nums[0];

    for (int i = 1; i < n; i++) {
        currMax = max(nums[i], currMax + nums[i]);
        maxSum = max(maxSum, currMax);

        currMin = min(nums[i], currMin + nums[i]);
        minSum = min(minSum, currMin);

        total += nums[i];
    }

    if (maxSum < 0)
        printf("%d", maxSum);
    else
        printf("%d", max(maxSum, total - minSum));

    return 0;
}

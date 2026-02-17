#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int max_sum = INT_MIN;
    int current_sum = 0;

    for(int i = 0; i < n; i++) {
        current_sum += nums[i];

        if(current_sum > max_sum) {
            max_sum = current_sum;
        }

        if(current_sum < 0) {
            current_sum = 0;
        }
    }

    printf("%d", max_sum);
    return 0;
}

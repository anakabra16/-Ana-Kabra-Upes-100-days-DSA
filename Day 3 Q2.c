n = int(input())          # total numbers supposed to be
arr = list(map(int, input().split()))

total_sum = n * (n + 1) // 2
array_sum = sum(arr)

missing = total_sum - array_sum
print("Missing number is:", missing)

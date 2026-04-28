void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {

  int i = m - 1;         // last valid in nums1
  int j = n - 1;         // last in nums2
  int k = nums1Size - 1; // last position

  while (i >= 0 && j >= 0) {
    if (nums1[i] > nums2[j]) {
      nums1[k--] = nums1[i--];
    } else {
      nums1[k--] = nums2[j--];
    }
  }

  // copy remaining nums2
  while (j >= 0) {
    nums1[k--] = nums2[j--];
  }
}
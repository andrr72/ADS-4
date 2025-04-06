// Copyright 2025 NNTU-CS

#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int leftCount = 1;
      while (left + leftCount < right && arr[left + leftCount] == arr[left]) {
        ++leftCount;
      }

      int rightCount = 1;
      while (right - rightCount > left && arr[right - rightCount] == arr[right]) {
        ++rightCount;
      }

      count += leftCount * rightCount;
      left += leftCount;
      right -= rightCount;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }

  return count;
}

int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (target < 0) break;

    int j = binarySearch(arr, i + 1, len - 1, target);

    if (j != -1) {
      int k = j;
      while (k + 1 < len && arr[k + 1] == target) {
        ++k;
      }
      count += (k - j + 1);
    }
  }

  return count;
}

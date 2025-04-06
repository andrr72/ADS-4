// Copyright 2025 NNTU-CS

#include <algorithm>

int countDuplicates(int *arr, int start, int end, int value) {
  int count = 0;
  while (start + count <= end && arr[start + count] == value) {
    ++count;
  }
  return count;
}

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
      int leftCount = countDuplicates(arr, left, right, arr[left]);
      int rightCount = countDuplicates(arr, right, left, arr[right]);
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
      int duplicates = countDuplicates(arr, j, len - 1, target);
      count += duplicates;
    }
  }

  return count;
}

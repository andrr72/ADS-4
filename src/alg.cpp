// Copyright 2025 NNTU-CS

int countPairs1(int* array, int size, int target) {
  int pairCount = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (array[i] + array[j] == target) {
        ++pairCount;
      }
    }
  }
  return pairCount;
}

int countPairs2(int* array, int size, int target) {
  int pairCount = 0;

  int upperBound = size - 1;
  while (upperBound > 0 && array[upperBound] > target) {
    --upperBound;
  }

  for (int i = 0; i < size; ++i) {
    for (int j = upperBound; j > i; --j) {
      if (array[i] + array[j] == target) {
        ++pairCount;
      }
    }
  }

  return pairCount;
}

int findFirstOccurrence(int* array, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (array[mid] >= target) {
      right = mid - 1;
    } 
    else {
      left = mid + 1;
    }
  }
  return left;
}

int findLastOccurrence(int* array, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (array[mid] <= target) {
      left = mid + 1;
    } 
    else {
      right = mid - 1;
    }
  }
  return right;
}

int countPairs3(int* array, int size, int target) {
  int pairCount = 0;

  for (int i = 0; i < size; ++i) {
    int complement = target - array[i];

    int start = findFirstOccurrence(array, i + 1, size - 1, complement);
    int end = findLastOccurrence(array, i + 1, size - 1, complement);

    if (start <= end) {
      pairCount += end - start + 1;
    }
  }

  return pairCount;
}

// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int end = len - 1;
  while (end > 0 && arr[end] > value) {
    end -= 1;
  }
  for (int leftIndex = 0; leftIndex < len; leftIndex++) {
    for (int rightIndex = end; rightIndex > leftIndex; rightIndex--) {
      if (arr[leftIndex] + arr[rightIndex] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int vtoroe = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == vtoroe) {
        count++;
        int j = mid - 1;
        while (j >= left && arr[j] == vtoroe) {
          count++;
          j--;
        }
        j = mid + 1;
        while (j <= right && arr[j] == vtoroe) {
          count++;
          j++;
        }
        break;
      } else if (arr[mid] < vtoroe) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}

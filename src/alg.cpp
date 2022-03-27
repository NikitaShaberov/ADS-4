// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}
int countPairs2(int* arr, int len, int value) {
  int counter = 0;
  int last = len;
  int rig = len - 1;
  for (int last = len - 1; arr[last] > value; last--) rig--;
  for (int i = 0; i <= len; i++) {
    if (arr[i] > value / 2) break;
    for (int j = rig; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
      if (arr[i] + arr[j] < value) break;
    }
  }
  return counter;
}

int countPairs3(int* arr, int len, int value) {
  int counter = 0;
  int end = len - 1;
  for (int i = 0; i < len - 1; i++) {
    bool result = false;
    int start = i + 1;
    int mid = (start + end) / 2;
    while (start <= end) {
      if (arr[mid] == value - arr[i]) {
        counter++;
        result = true;
        break;
      } else if (arr[mid] > value - arr[i]) {
        end = mid - 1;
      } else if (arr[mid] < value - arr[i]) {
        start = mid + 1;
      }
      mid = (start + end) / 2;
    }
    int temp1 = mid;
    int temp2 = mid;
    if (result == true) {
      while (arr[temp1 - 1] == arr[mid] && temp1 - 1 != i) {
        counter++;
        temp1--;
      }
      while (arr[temp2 + 1] == arr[mid]) {
        counter++;
        temp2++;
      }
    }
  }
  return counter;
}

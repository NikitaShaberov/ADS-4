// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int lenght, int value) {
int num = 0;
for (int i = 0; i < lenght - 1; i++) {
  for (int j = i + 1; j < lenght; j++) {
    if (arr[i] + arr[j] == value)
      num++;
  }
}
return num;
}
int countPairs2(int *arr, int lenght, int value) {
int num = 0;
int l = lenght;
int r = lenght - 1;
for (int z = lenght - 1; arr[l] > value; l--)
  r--;
for (int i = 0; i <= lenght; i++) {
  if (arr[i] > value / 2)
    break;
  for (int j = r; j > i; j--) {
    if (arr[i] + arr[j] == value) {
      num++;
    }
    if (arr[i] + arr[j] < value)
      break;
  }
}
return num;
}
int countPairs3(int *arr, int lenght, int value) {
int num = 0;
int r = lenght - 1;
for (int i = 0; i < lenght - 1; i++) {
  bool res = false;
  int l = i + 1;
  int mid = (l + r) / 2;
  while (l <= r) {
    if (arr[i] + arr[mid] == value) {
      num++;
      res = true;
      break;
    } else if (arr[mid] > value - arr[i]) {
      r = mid - 1;
    } else if (arr[mid] < value - arr[i]) {
      l = mid + 1;
    }
    mid = (l + r) / 2;
  }
  int cur1 = mid;
  int cur2 = mid;
  if (res == true) {
    while (arr[cur1 - 1] == arr[mid] && cur1 - 1 != i) {
      num++;
      cur1--;
    }
    while (arr[cur2 + 1] == arr[mid]) {
      num++;
      cur2++;
    }
  }
}
return num;
}

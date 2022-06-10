// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int par = 0;
for (int i = 0; i < len - 1; i++) {
  for (int j = i + 1; j < len; j++) {
    if (arr[i] + arr[j] == value)
      par++;
  }
}
return par;
}
int countPairs2(int *arr, int len, int value) {
int par = 0;
int l = len;
int r = len - 1;
for (int z = len - 1; arr[l] > value; l--)
  r--;
for (int i = 0; i <= len; i++) {
  if (arr[i] > value / 2)
    break;
  for (int j = r; j > i; j--) {
    if (arr[i] + arr[j] == value) {
      par++;
    }
    if (arr[i] + arr[j] < value)
      break;
  }
}
return par;
}
int countPairs3(int *arr, int len, int value) {
int par = 0;
int r = len - 1;
for (int i = 0; i < len - 1; i++) {
  bool res = false;
  int l = i + 1;
  int mid = (l + r) / 2;
  while (l <= r) {
    if (arr[i] + arr[mid] == value) {
      par++;
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
      par++;
      cur1--;
    }
    while (arr[cur2 + 1] == arr[mid]) {
      par++;
      cur2++;
    }
  }
}
return par;
}

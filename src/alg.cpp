// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int par = 0;
for (int i = 0; i < len-1; i++) {
  for (int j = i+1; j < len; j++) {
    if (arr[i] + arr[j] == value) {
      par++;
    }
  }
}
return par;
return 0;
}
int countPairs2(int *arr, int len, int value) {
int l = 0;
int r = len-1;
int par = 0;
for (int i = len - 1; i > 0; i--) {
  if (value == arr[i]) {
    r = i;
  }
}
for (int i = l; i < len - 1; i++) {
  for (int j = r; j > i - 1; j--) {
    if (arr[i] + arr[j] == value) {
                par++;
    }
  }
}
return par;
return 0;
}
int countPairs3(int *arr, int len, int value) {
int par = 0;
int l = 0;
int r = len-1;
for (int i = 0; i < len - 1; i++) {
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[i] + arr[mid] == value) {
      par++;
      int j = mid + 1;
      while (arr[i] + arr[j] == value && j < r) {
        par++;
        j++;
      }
      j = mid - 1;
      while (arr[i] + arr[j] == value && j > l) {
        par++;
        j--;
      } 
      break;
    }
    if (arr[i] + arr[mid] > value) {
      r = mid;
    } else {
        l = mid;
      }
  }
}
return par;
return 0;
}

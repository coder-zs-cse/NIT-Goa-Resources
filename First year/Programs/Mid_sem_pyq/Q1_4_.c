#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// int max(int a,int b){
//   return a>b ? a:b;
// }
int main()
{
  int n;
  scanf("%d", &n);
  int *array = (int *)calloc(n, sizeof(int));
  int *dup = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++){
    int element;
    scanf("%d", &element);
    array[i] = element;
  }
  for (int i = 0; i < n; i++){
    int count = 1;
    if (dup[i] != -1){
      for (int j = i + 1; j < n; j++){
        if (array[j] == array[i]){
          count++;
          dup[j] = -1;
        }
      }
      dup[i] = count;
    }
  }
  for (int i = 0; i < n; i++){
    if (dup[i] != -1) printf("%d ", array[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++){
    if (dup[i] != -1)   printf("%d ", dup[i]);
  }
  return 0;
}
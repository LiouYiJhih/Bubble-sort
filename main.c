/* Bubble Sort
1. 使用交換方式進行排序
e.g. 撲克牌攤開在桌上排成一列，將相鄰兩張牌的值進行比較，沒有照順序排序則交換，直到排序正確為止。
        [0]  [1]  [2]  [3]  [4]  [5]
begin    k    l    j    o    a    b
1       [k   l]    j    o    a    b     不交換
2        k   [j   l]    o    a    b     交換
3        k    j   [l   o]    a    b     不交換
4        k    j    l   [a   o]    b     交換
5        k    j    l    a   [b    o]    交換
走訪一次結果
*/
/* 
時間複雜度 
最好 : 鍵值已排序好，需要比較，但是不用交換 O(n))
最差 : 鍵值相反排序，需要比較，也需要交換 O(n^2))
平均 : O(n^2))
空間複雜度 : 不用額外記憶體空間，除了變數 temp
穩定性 : 穩定性，相同鍵值不用交換
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20

void bubbleSort(char* data,int length)
{
  int i, j; 
  char temp;
  // 每次執行一次走訪，則會確認最後一個泡泡
  // 因此陣列長度減一
  for(i = length;i > 1; i--)
  {
    // N個資料，要比較N-1次
    for(j = 0;j < i-1;j++)
    {
      if(data[j+1] < data[j])
      {
        temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
    // 輸出每次走訪的結果
    printf("%d : [%s]\n",length-i+1,data);
  }
}

int main()
{
  char data[MAX_LEN] = "kljoab";
  int len;
  
  len = strlen(data);
  bubbleSort(data, len);
  printf("排序結果[%s]\n",data);
}
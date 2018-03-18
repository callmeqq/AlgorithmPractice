#include <iostream>
#include <string>
using namespace std;
#include "Sort.h"
#include "DP.h"
#include "KMP.h"
#define getArrayLength(array, length){ length =  sizeof(array) / sizeof(array[0]); }

int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    int arr[] = {2, 5, 3, 1, 3, 6, 3};
//    int arr_len = 0;
//    getArrayLength(arr, arr_len);
////    printf("arr_len=%d\n", arr_len);
//    MergeSort(arr, 0, 6);
//    QuickSort(arr, 0, arr_len - 1);
//    for (int i = 0; i < 7; ++i) {
//        printf("%d", arr[i]);
//    }

    int p[] = {5,10,20,50,10};
    int n = 5;
    int s[6][6];
    int m[6][6];
    memset(s,0,sizeof(s));
    memset(m,0,sizeof(m));
    DP_MatrixChain(p, n, (int **)m, (int **)s);

    return 0;
}


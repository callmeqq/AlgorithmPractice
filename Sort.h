//
// Created by QQ on 2017/10/11.
//

#ifndef ALGORITHMPRACTICE_QUICKSORT_H
#define ALGORITHMPRACTICE_QUICKSORT_H
#define ArrLen(array, length){ (length) =  sizeof(array) / sizeof((array)[0]); }
void QuickSort(int arr[], int l, int r);
void MergeSort(int arr[], int left, int right);
void HeapSort(int arr[], int length);
#endif //ALGORITHMPRACTICE_QUICKSORT_H

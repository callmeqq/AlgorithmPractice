#include "Sort.h"

/**
 * 交换两个数
 * 参数要加 " & "，否则交换无效
 */
void swap(int &a, int &b) {
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

/**
 * 快速排序
 * @param arr 需要排序的数组
 * @param l 待排序数组的左边界
 * @param r 待排序数组的右边界
 */
void QuickSort(int arr[], int l, int r) {
    //递归的结束条件
    if (l >= r) {
        return;
    }
    //初始化迭代器和 key
    int i = l, j = r;
    int key = arr[i];
    //将小于key值的数往左边扔，大于key的值往右边扔
    while (i < j) {

        while (arr[j] >= key && i < j) {
            j--;
        }
        arr[i] = arr[j];

        while (arr[i] <= key && i < j) {
            i++;
        }
        arr[j] = arr[i];

    }
    arr[i] = key;
    //递归操作
    QuickSort(arr, l, i - 1);
    QuickSort(arr, i + 1, r);
}

/**
 * 归并排序中的归并算法
 * @param arr 待合并的数组
 * @param left 数组的左边界
 * @param right 数组的右边界
 * @param mid 数组的中间位置
 */
void Merge(int arr[], int left, int right, int mid){

    int i;// 左边数组的索引
    int j;// 右边数组的索引
    int k;// 临时数组的索引

    int arr_len = right - left + 1;//临时数组大小
    int tmp_arr[arr_len];

    for (i = left, j = mid + 1, k = 0; k <= right - left; k++) {

        //当左边数组遍历完成后，直接把右边数组剩余的数填充到临时数组中
        if (i == mid + 1) {
            tmp_arr[k] = arr[j++];
            //结束本次循环
            continue;
        }
        if (j == right + 1) {
            tmp_arr[k] = arr[i++];
            continue;
        }
        if (arr[i] < arr[j]) {
            tmp_arr[k] = arr[i++];
        } else {
            tmp_arr[k] = arr[j++];
        }

    }
    //将已经排好序的临时数组复制回原数组
    for (int i = left, j = 0; i <= right; i++, j++) {
        arr[i] = tmp_arr[j];
    }

}
/**
 * 归并排序
 * @param arr 待排序数组
 * @param left 待排序数组的左边界
 * @param right 待排序数组的右边界
 */
void MergeSort(int arr[], int left, int right) {

    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, right, mid);
}

/**
 * 维护一个堆
 * @param arr 需要排序的数组
 * @param i 需要维护堆的位置
 * @param length 数组长度
 */
void Heap(int arr[], int i, int length) {
    //子节点的位置
    int child = i * 2 + 1;
    //当i * 2 + 1 也就是子节点存在时循环
    for (;i * 2 + 1< length;i = child) {

        if (arr[child]<arr[child+1]&&child+1<length)
            child++;

        if (arr[i] < arr[child]) {
            swap(arr[i], arr[child]);
        } else {
            break;
        }
    }
}

/**
 * 堆排序算法
 * @param arr 待排序数组
 * @param length 带排序数组长度
 */
void HeapSort(int arr[], int length){
    //将数组形成一个堆
    //length / 2 - 1 为倒数第二层最后的节点，开始维护一个堆
    for (int i = length / 2 - 1; i >= 0; --i) {
        Heap(arr, i, length);
    }

    for (int j = length - 1; j > 0; j--) {
        //堆顶和堆尾交换位置，堆顶为整个堆最大的元素
        swap(arr[0], arr[j]);
        //继续维护一个堆，且维护的长度减一
        Heap(arr, 0, j);
    }
}


# 快速排序
-----
![alt 初始化](./picture/quicksort1.png)
-----
![alt ](./picture/quicksort2.png)
![alt ](./picture/quicksort3.png)
![alt ](./picture/quicksort4.png)
-----
### 快速排序每趟排序都可以确定一个数(key)的位置，并保证左边的数小于等于key，右边的数大于等于key，但是不能保证其顺序

### 继续对左边和右边进行递归操作，就可以完成整个数组的排序
![alt ](./picture/quicksort5.png)
### c语言实现代码
```c
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
```
###测试样例
```c
//获取数组长度函数
#define getArrayLength(array, length){ length =  sizeof(array) / sizeof(array[0]); }

int main() {

    int arr[] = {2, 5, 3, 1, 3, 6, 3};
    //先初始化一个变量，用来保存数组长度
    int arr_len = 0;
    getArrayLength(arr, arr_len);

    QuickSort(arr, 0, arr_len - 1);

    for (int i = 0; i < arr_len; ++i) {
        printf("%d", arr[i]);
    }

    return 0;
}

```
-----
# 归并排序
# 堆排序
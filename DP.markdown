# DP 动态规划
## 矩阵连乘问题
-----
如 矩阵 A1[5 \* 10] , A2[10 \* 20] , A3[20 \* 50] , A4[50 \* 10]<br>
求 矩阵链A1，A2，A3，A4 最少计算次数<br>
> 思路：子问题划分，将一个大问题划分成多个子问题，再由子问题的最优解得出最终问题的解  
如例子求4个矩阵连乘，可先求2个矩阵连乘，3个矩阵连乘...
![alt 自底向上求出各个子问题的解](./picture/dp1.png)
自底向上求出各个子问题的解

### 算法描述

定义两个矩阵 

- M 矩阵：保存当前矩阵链 最优解(最少计算次数) 的二维数组
- S 矩阵：保存当前矩阵链 最优解(最少计算次数) 的* 断开位置 k *的二维数组

解释下什么是断开位置
![alt 什么是断开位置](./picture/dp2.png)
![alt ](./picture/dp3.png)
> i 表示子链起始位置，j 表示子链结束位置 如 S\[1\]\[3\] 表示 子链 A1A2A3 ,   S\[2\]\[4\] 表示 子链 A2A3A4

![alt ](./picture/dp4.png)
![alt ](./picture/dp5.png)
![alt ](./picture/dp6.png)
> 当断开点k=1时 分为两个子链 A1 和 A2A3  
A1 = \[5 \* 10\] ，A2A3 = \[10 \* 50\]  
A1(A2A3)的计算次数为 5 \* 10 \* 50 ，但是这样没有计算 A2 * A3 的次数，这些次数之前已经计算过了，即为m \[1\]\[1\]，m \[2\]\[3\]

可以推出一个通用公式：计算次数 = m \[i\]\[k\] + m \[k+1\]\[j\] + p \[i-1\] \* p \[k\] \* p \[j\]
![alt ](./picture/dp7.png)
此时，已经计算完了所有子链，最少计算次数则为m \[1\]\[4\] = 8500，而计算方法则需要通过 S矩阵 递归求解
![alt ](./picture/dp8.png)
--- 
### c语言实现代码
上述计算过程中，链长循环一次，相同链长不同链循环一次，每种子链的不同断开方式循环一次，共有三层循环
```c
void MatrixChain(int i, int j, int **s, int n);
/**
 *
 * @param p 矩阵链数组 如三个矩阵为[A1,A2,A3] = [5*10,10*20,20*50],则矩阵链数组为[5,10,20,50]
 * @param n 矩阵链数组长度
 * @param m 存放当前链最少计算次数的二维数组 行为链表起始位置，列为链表结束位置 1行2列即为 A1*A2，1行3列即为 A1*A2*A3
 * @param s 存放当前链最少计算次数时的断开位置 断开位置是 2，即计算方法为 (A1*A2)*A3
 */
void DP_MatrixChain(int p[], int n, int **m, int **s){
    //当矩阵链长为1时，无法相乘，运算次数为0
    for (int i = 1; i < n; i++) {
        *((int *)m +i*n +i) = 0;
    }
    //r为链长，从2开始
    for (int r = 2; r < n; r++) {
        //i 为行号，
        for (int i = 1; i < n - r + 1; i++) {
            //j 为列号
            int j = i + r - 1;
            //寻找子问题的最优解，以第一个断开点为参照，比较每一个断开点
            *((int *)m +i*n +j) = *((int *)m +(i+1)*n +j) + p[i - 1] * p[i] * p[j];
            *((int *)s +i*n +j) = i;
            //k为断开点位置，k = 2 则在第二个和第三个矩阵中间断开
            for (int k = i+1; k < j; k++) {
                int tmp = *((int *)m +i*n +k) + *((int *)m +(k+1)*n +j) + p[i - 1] * p[k] * p[j];
                if (tmp < *((int *)m +i*n +j)) {
                    *((int *)m +i*n +j) = tmp;
                    *((int *)s +i*n +j) = k;
                }
            }
        }
    }
    MatrixChain(1, n - 1, s, n);
    printf("\n");
    // 打印s矩阵
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d\t",*((int *)s +i*n +j));
        }
        printf("\n");
    }
    //打印m矩阵
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d\t\t",*((int *)m +i*n +j));
        }
        printf("\n");
    }
}

void MatrixChain(int i, int j, int **s, int n){
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    MatrixChain(i, *((int *) s + i * n + j), s, n);
    MatrixChain(*((int *) s + i * n + j) + 1, j, s, n);
    printf(")");
}
```
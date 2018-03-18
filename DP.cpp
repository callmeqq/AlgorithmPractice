//
////矩阵连乘问题 计算最优解
//
#include <printf.h>
#include <iostream>

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
//// 测试用例
// int p[] = {5,10,20,50,10};
// int n = 5;
// int s[6][6];
// int m[6][6];
// memset(s,0,sizeof(s));
// memset(m,0,sizeof(m));
// DP_MatrixChain(p, n, (int **)m, (int **)s);


//
//// ------- 0-1背包问题 -----------------
//

/**
 * 0-1背包问题
 * @param v 物品价值数组
 * @param w 物品质量数组
 * @param c 背包容量
 * @param n 物品总数
 */
void DP_Knapsack(int v[],int w[],int c, int n){

    //存放前n个物品背包容量为c时的最优情况
    int f[n + 1][c + 1];

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= c; ++j) {
            //当背包容量小于物品容量时
            if (w[i] > j) {
                //无法放入背包，即放入背包的物品价值和前 n - 1 个一样
                f[i][j] = f[i - 1][j];
            } else {
                //不放入背包
                int tmp_x = f[i - 1][j];
                //放入背包，即（放入背包）的物品价值为前 n - 1 个物品加上（当前物品） 的价值
                int tmp_y = f[i - 1][j - w[i]] + v[i];
                //将最优情况放入数组
                f[i][j] = (tmp_x > tmp_y) ? tmp_x : tmp_y; //max 函数莫名其妙用不了，用三目运算符替代
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < c; ++j) {
            printf("%d ", f[i][j]);
        }
        printf("\n");
    }
}
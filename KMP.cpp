#include "KMP.h"
#include <string>

/**
 * 未优化的next数组求法
 * @param p 模式串
 * @param next 模式串对应的next数组
 * @param pLen 模式串长度
 */
void getNextArray_1(char p[],int next[], int pLen){

    int j = 0;// 模式串数组 p 的索引
    int k = -1;// 最长相同前缀后缀的索引
    next[0] = -1;//
    while (j < pLen - 1) {

        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

/**
 * 优化后的next数组求法
 * @param p 模式串
 * @param next 模式串对应的next数组
 * @param pLen 模式串长度
 */
void getNextArray(char p[],int next[], int pLen){

    int j = 0;// 模式串数组 p 的索引
    int k = -1;// 最长相同前缀后缀的索引
    next[0] = -1;//
    while (j < pLen - 1) {

        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;

            if (p[j] != p[k]) {
                next[j] = k;
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
}

/**
 * KMP算法
 * @param s 文本串
 * @param p 模式串
 * @return 匹配成功的位置
 */
int KMP(char s[], char p[]){
    int i = 0;
    int j = 0;
    int pLen = strlen(p);
    int sLen = strlen(s);
    if (pLen > sLen) {
        return -1;
    }
    int next[pLen];
    getNextArray(p, next, pLen);
    while (i < sLen && j < pLen) {
        if (p[j] == s[i] || j == -1) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == pLen) {
        return i - j;
    } else {
        return -1;
    }
}
////    测试用例
////    char s[]="abcdabcdabcdd";
////    char p[]="bcdd";
////    int position = KMP(s, p);
////    cout<<position<<endl;

/// http://blog.csdn.net/v_july_v/article/details/7041827
/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。

n<=39
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
//运行时间：4ms
//占用内存：480k
//动态规划就是强呀！
class Solution {
public:
    int Fibonacci(int n) {
        if(n==1 || n==2)
            return 1;
        int dp[40];
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
int main() {

    return 0;
}

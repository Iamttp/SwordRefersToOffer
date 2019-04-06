/*
 * 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        int *dp = new int[number + 1];
        for (int i = 1; i <= number; ++i) {
            if (i == 1)
                dp[i] = 1;
            else if (i == 2)
                dp[i] = 2;
            else {
                dp[i] = 0;
                for (int j = i - 1; j > 0; --j) {
                    dp[i] += dp[j];
                }
                dp[i]++;
            }
        }
        return dp[number];
    }
};

int main() {

    return 0;
}

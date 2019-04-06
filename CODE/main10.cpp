/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        int *dp = new int[number + 1];
        for (int i = 1; i <= number; ++i) {
            if (i == 1)
                dp[i] = 1;
            else if (i == 2)
                dp[i] = 2;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};

int main() {

    return 0;
}

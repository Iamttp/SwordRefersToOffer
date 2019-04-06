/*
 * 题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

// sprintf 完美判断16种情况haha
//class Solution {
//public:
//    int NumberOf1(int n) {
//        int res = 0;
//        char x[100];
//        sprintf(x, "%x", n);
//        for (int i = 0; i < strlen(x); ++i) {
//            if (x[i] == 'f')
//                res += 4;
//            if (x[i] == 'e' || x[i] == 'd' || x[i] == 'b' || x[i] == '7')
//                res += 3;
//            if (x[i] == 'c' || x[i] == '9' ||
//                x[i] == 'a' || x[i] == '3' || x[i] == '5' || x[i] == '6')
//                res += 2;
//            if (x[i] == '1' || x[i] == '2' || x[i] == '4' || x[i] == '8')
//                res += 1;
//            if (x[i] == '0')
//                res += 0;
//        }
//        return res;
//    }
//};

//  大神的代码
class Solution {
public:
    static int NumberOf1(int n) {
        int count = 0;
        while (n != 0) {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }
};

int main() {
    Solution s;
    s.NumberOf1(-6);
    return 0;
}

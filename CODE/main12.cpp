/*
 * 题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    double myPower(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        } else if (exponent % 2 == 1) {
            return base * myPower(base * base, exponent / 2);
        } else {
            return myPower(base * base, exponent / 2);
        }
    }

    double Power(double base, int exponent) {
        if (exponent > 0)
            return myPower(base,exponent);
        else
            return 1/myPower(base,-exponent);
    }
};

int main() {

    return 0;
}

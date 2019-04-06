/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for (int i = array.size() - 1; i >= 0; --i) {
            if (array[i] % 2 == 0) {
                while (i < array.size() && array[i + 1] % 2 != 0) {
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                    i++;
                }
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> x{1, 3, 4, 2, 6, 5, 8};
    s.reOrderArray(x);
    for (auto x1:x) {
        cout << x1 << " ";
    }
    return 0;
}

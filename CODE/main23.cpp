/*
 * 题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST2(vector<int> sequence) {
        if (sequence.empty()) {
            return true;
        }
        bool res;
        int rootValue = sequence.back();
        int i;
        for (i = 0; i < sequence.size(); ++i)
            if (sequence[i] >= rootValue)
                break;
        for (int j = i; j < sequence.size(); ++j)
            if (sequence[j] < rootValue)
                return false;
        vector<int> v1(sequence.begin(), sequence.begin() + i);
        vector<int> v2(sequence.begin() + i, sequence.end() - 1);
        return VerifySquenceOfBST2(v1) && VerifySquenceOfBST2(v2);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return false;
        }
        return VerifySquenceOfBST2(sequence);
    }
};

int main() {
    Solution s;
    cout << s.VerifySquenceOfBST(vector<int>{1, 3, 2, 5, 7, 6, 4});
    return 0;
}
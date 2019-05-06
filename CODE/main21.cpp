/*题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 自己构造一个栈来检验
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty())
            return false;
        stack<int> st;
        int i = 0, j = 0;
        while ((unsigned int) (i) < pushV.size()) {
            st.push(pushV[i++]);
            while (j < popV.size() && st.top() == popV[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    solution.IsPopOrder(vector<int>{1, 2, 3, 4, 5}, vector<int>{4, 5, 3, 2, 1});
    return 0;
}
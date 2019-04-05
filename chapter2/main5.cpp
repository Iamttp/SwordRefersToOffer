/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
using namespace std;
//运行时间：3ms
//占用内存：492k
//画图表示
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()==0)
            while (stack1.size()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        int res = stack2.top();
        stack2.pop();
        return res;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
int main() {
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop();
    s.push(4);
    s.push(5);
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
    return 0;
}

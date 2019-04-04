/*
 * 题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

//运行时间：4ms
//占用内存：376k
class Solution {
public:
    void replaceSpace(char *str, int length) {
        string s = str;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                s.replace(s.begin()+i, s.begin()+i+1,"%20");
            }
        }
        //这种方法只是改变了str指针指向
//        str = (char *)s.c_str();

        //这种方法改变了str指向的内存的值
        int j = 0;
        for (; j < s.size(); ++j) {
            str[j] = s[j];
        }
        //记住手动加'\0'
        str[j] = '\0';
    }
};

int main() {
    Solution s;
    char a[] = " I am ttp";
    s.replaceSpace(a,8);
    cout << a;
    return 0;
}

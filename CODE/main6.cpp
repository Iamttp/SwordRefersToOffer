/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
//运行时间：44ms
//占用内存：976k
//class Solution {
//public:
//    int minNumberInRotateArray(vector<int> rotateArray) {
//        if(rotateArray.size()==0)
//            return 0;
//        sort(rotateArray.begin(),rotateArray.end());
//        return rotateArray[0];
//    }
//};

//运行时间：32ms
//占用内存：632k
//最害怕二分查找的边界问题QAQ
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int l = 0, r = rotateArray.size() - 1;
        int mid;
        while (l < r) {
            mid = (l + r) / 2;
            if(rotateArray[mid]>rotateArray[l])
                l = mid;
            else if(rotateArray[mid]<rotateArray[r])
                r = mid;
            else
                break;
        }
        return min(rotateArray[mid],rotateArray[mid+1]);
    }
};

int main() {
    Solution s;
    cout << s.minNumberInRotateArray(vector<int>{4,5,6,7,8,1,2,3});
    return 0;
}

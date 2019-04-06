/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <iostream>
#include <vector>

using namespace std;

// 自己写的出现了段错误
//class Solution {
//public:
//    int Find2(vector<int> ary, int target){
//        //大
//        if(target>*(ary.end()-1))
//            return -1;
//        //小
//        if(target<ary[0])
//            return -2;
//        int l = 0, r = ary.size() - 1;
//        int mid;
//        while (l < r) {
//            mid = (l + r) / 2;
//            if(ary[mid] == target)
//                break;
//            else if(ary[mid] < target)
//                l = mid + 1;
//            else
//                r = mid;
//        }
//        // 找到
//        if(ary[mid] == target)
//            return mid;
//        else
//            return -3;
//    }
//
//    bool Find(int target, vector<vector<int> > array) {
//        int i = array.size()/2;
//        while (i>=0&&i<array.size()){
//            vector<int> temp = array[i];
//            int y = Find2(temp,target);
//            if(y==-1){
//                i++;
//            } else if(y==-2){
//                i--;
//            } else if(y==-3){
//                return false;
//            } else{
//                return true;
//            }
//        }
//        return false;
//    }
//};

// 别人的思路
//运行时间：11ms
//占用内存：1620k
/* 思路
* 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
* 因此从左下角开始查找，当要查找数字比左下角数字大时。右移
* 要查找数字比左下角数字小时，上移
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        int n = array[0].size();

        int nowData = array[m - 1][0];
        int nowm = m - 1;
        int nown = 0;

        while (nowm >= 0 && nown < n) {
            if (nowData < target) {
                nown++;
            } else if (nowData > target) {
                nowm--;
            } else {
                return true;
            }
            nowData = array[nowm][nown];
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> x1{1, 2, 3, 4, 5};
    vector<int> x2{2, 3, 4, 5, 13};
    vector<int> x3{3, 4, 5, 11, 22};
    vector<vector<int>> x{x1, x2, x3};
    cout << s.Find(10, x);
    return 0;
}
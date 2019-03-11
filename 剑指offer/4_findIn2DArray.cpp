/*
    题目描述
    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
    请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
/*
    二维数组每行是从小到大排列的。每列也是从小到大的根据这个规律
    可以用要查找的数字与二维数组的右上角数字对比，如果比它大就去掉右上角元素所在的那一行，小于就去掉它所在的那一列
    逐渐减小搜索范围
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int width=array[0].size();
        int length=array.size();
        length=length-1;
        int w=0;
        while(length>=0&&w<=width-1)
        {
            if(target==array[length][w])
                return true;
            if(target<array[length][w])
                length--;
            else
                w++;
        }
        return false;
    }
};
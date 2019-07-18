/*
    给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。

    示例 1:

    输入: candies = [1,1,2,2,3,3]
    输出: 3
    解析: 一共有三种种类的糖果，每一种都有两个。
         最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
    示例 2 :

    输入: candies = [1,1,2,3]
    输出: 2
    解析: 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多。
    注意:

    数组的长度为[2, 10,000]，并且确定为偶数。
    数组中数字的大小在范围[-100,000, 100,000]内。
*/
/*
    数组长度为偶数N，那么糖果被两人平分，妹妹拿到的糖果种类最多为N/2种
    只要将数组排序，每种糖给妹妹一个，直到达到N/2个或者全发完
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        if(candies.empty())
            return 0;
        // 排序
        sort(candies.begin(), candies.end());
        int res=0;
        for(int i=0;i<candies.size();i++)
        {
            if(i>0&&candies[i]==candies[i-1])
                continue;
            res++;
            if(res>=candies.size()/2)
                break;
        }
        return res;
        
        /*
        // 最简单的方法 利用set
        unordered_set<int> s(candies.begin(), candies.end());
        return s.size()>=candies.size()/2 ? candies.size()/2:s.size();
        */
    }
};
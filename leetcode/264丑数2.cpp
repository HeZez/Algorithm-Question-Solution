/*
    编写一个程序，找出第 n 个丑数。

    丑数就是只包含质因数 2, 3, 5 的正整数。

    示例:

    输入: n = 10
    输出: 12
    解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
    说明:  

    1 是丑数。
    n 不超过1690。
*/
/*
    一开始没想到方法，最暴力的方法就是从小到大逐个去试，并记录丑数的个数
    时间开销低的方法猜测可能和欧拉筛类似
    
    剑指offer上提供了一个三指针的方法，类似动态规划 因为有三个质因数2 3 5 新的丑数肯定是由前面的丑数
    乘以这三个质因子得来的。于是用一个数组来存储之前出现过的所有丑数，之后用三个指针
    每个指针分别指向乘以三个不同质因子后，比当前最大丑数还大的最小丑数
    
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        int t1=0,t2=0,t3=0;
        //int temp1=0,temp2=0,temp3=0;
        vector<int> ulgy;
        ulgy.push_back(1);
        while(ulgy.size()<n)
        {
            while(ulgy[t1]*2<=ulgy.back())
                t1++;
            while(ulgy[t2]*3<=ulgy.back())
                t2++;
            while(ulgy[t3]*5<=ulgy.back())
                t3++;
            //cout<<t1<<t2<<t3<<min(min(ulgy[t1]*2, ulgy[t2]*3), ulgy[t3]*5)<<endl;
            ulgy.push_back( min(min(ulgy[t1]*2, ulgy[t2]*3), ulgy[t3]*5) );
        }
        return ulgy.back();
    }
};
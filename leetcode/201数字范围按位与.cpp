/*
    给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

    示例 1: 

    输入: [5,7]
    输出: 4
    示例 2:

    输入: [0,1]
    输出: 0
*/
/*
    最直接的做法就是每个数循环一遍，做与运算
    但是试了一下之后，发现在0到2147483647这样的数据上会超时
    
    所以还是要思考一下规律， 按位做与运算，所有的数字中只要有一个数字在某一位为0
    结果的这一位就为0，按照这个思路，可以依次判断int 32位的每一位
    
    如果两个二进制数长度不同，这两个数字范围之内的数做按位与 结果一定是0
    举个例子  110 和10  10想要增长到110 必然经过100 再加上一开始的时候10少一位 要看成010
    这样所有的位都出现过0.
    
    如果两个二进制数长度相同，则该问题结果是从前到后二进制相同位所表示的二进制数
    101和111 结果就是100
    这个思路能过 是正确的 ，但是时间空间都比较差。。。。。。
    
    这个思路本质上就是找公共前缀  有没有优雅一点的方法实现呢？
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res=0;
        /*
        // 暴力不可取
        for(int i=1;i<=(n-m);i++)
            res=res&(m+i);
        return res;
        */
        vector<int> mB=int2Binary(m);
        vector<int> nB=int2Binary(n);
        if(mB.size()!=nB.size())
            return res;
        else
        {
            int i=0;
            while(i<mB.size()&&mB[i]==nB[i])
            {
                res+=pow(2, mB.size()-i-1)*mB[i];
                i++;
            }
        }
        return res;
    }
    vector<int> int2Binary(int num)
    {
        vector<int> res;
        while(num>0)
        {
            res.push_back(num%2);
            num/=2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
/*
    给定一个整数 n, 返回从 1 到 n 的字典顺序。

例如，

给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。

请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
*/
/*
    最直观的想法，创建从1到n数字的字符数组，之后对字符数组按字典序排序，再把字符串转换为数字
    这样的话 时间复杂度排序是O(nlogn) 但是之间的转换操作应该也比较耗时 空间复杂度O（n）
    最直接的是使用stl中的sort函数 但是自己写cmp函数时要注意  sort函数需要的cmp函数是一个普通函数指针，如果写在类内就变成了成员函数指针， 所以要写成静态方法。

    果不其然 这种粗暴的方法效率很低

    更通用和优秀的思路是通过递归的方式进行搜索
    这个问题可以理解成，在1到n的这么多数字中按照字典序排序的话 因为第一位数字不会是0 所以有1到9开头的九组
    之后在1-9开头分成的九组中，每一组还可以有0到9的十组， 以此类推。
    这个形式评论区有人看成了十叉树的遍历，或者dfs，递归来解决也是相同的含义

*/
class Solution {
public:
    /*
    // 自己的拙劣想法
    static bool cmp(const int f, const int s)
    {
        
        string sf, ss;
        sf=int_to_str(f);
        ss=int_to_str(s);
        return sf<ss;
        
        //return f>s;
    }
    static string int_to_str(const int n)
    {
        string ss;
        int temp=n;
        while(temp>0)
        {
            ss+=(temp%10+'0');
            temp/=10;
        }
        reverse(ss.begin(), ss.end());
        return ss;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> nv(n, 0);
        for(int i=0;i<n;i++)
        {
            nv[i]=i+1;
        }
        sort(nv.begin(), nv.end(), cmp);
        return nv;
    }
    */

    // 递归写法
    vector<int> result;
    vector<int> lexicalOrder(int n) {
        lexicalOrderCore(0, n);
        return result;
    }
    void lexicalOrderCore(int temp, int& n)
    {
        if(temp==0)
        {
            for(int i=1;i<=9;i++)
            {
                if(temp*10+i<=n)
                {
                    result.push_back(temp*10+i);
                    lexicalOrderCore(temp*10+i, n);
                }
            }
        }
        else
        {
            for(int i=0;i<=9;i++)
            {
                if(temp*10+i<=n)
                {
                    result.push_back(temp*10+i);
                    lexicalOrderCore(temp*10+i, n);
                }
            }
        }
    }
};
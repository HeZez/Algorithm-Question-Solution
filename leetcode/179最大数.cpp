/*
    给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

    示例 1:
    输入: [10,2]
    输出: 210
    
    示例 2:
    输入: [3,30,34,5,9]
    输出: 9534330
    说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/
/*
    如果每一次从数组中找一个数，之后把这个数去掉，之后再在剩余数字中找合适的数字
    这样做时间复杂度是O(N!) 不可取
    
    实际上要做的是排序，只不过排序规则有变化
    排序规则是这样的
    例如30 和9两个数字
    比较两种组合 309 和930 930>309 则9比30大
    
    同时还要注意数据中全是0的情况
*/
class Solution {
// compare函数要求是全局或者静态的
// 降序排列
static bool compareMyself(int num1, int num2)
    {
        string numS1=intTwoString(num1);
        string numS2=intTwoString(num2);
        long comNum1=stringToLong(numS1+numS2);
        long comNum2=stringToLong(numS2+numS1);
        return comNum1>comNum2;
    }
    
static long stringToLong(string s)
{
    long res=0;
    int length=s.size();
    for(int i=0;i<length;i++)
    {
        res+=(pow(10, length-i-1)*(s[i]-'0'));
    }
    return res;
}
static string intTwoString(int num)
{
    // 要求中说明了所有数字非负
    string res="";
    int oneBit=0;
    // 单独处理一下0
    if(num==0)
        return "0";
    while(num>0)
    {
        oneBit=num%10;
        res+=('0'+oneBit);
        num/=10;
    }
    reverse(res.begin(), res.end());
    return res;
}
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end(), compareMyself);
        
        for(auto it: nums)
        {
            res+=intTwoString(it);
        }
        return res[0]=='0'? "0":res;  // 处理全是0的情况，如果开头第一个数字是0 根据排序规则 后面都是0 输出一个即可
    }  
};
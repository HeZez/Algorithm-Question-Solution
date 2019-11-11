/*
    给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

    示例 :

    输入: [1,2,1,3,2,5]
    输出: [3,5]
    注意：

    结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
    你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
*/
/*
    最简单想法是map计数
    
    线性复杂度异或运算
    因为有两个数字出现了一次，其余的都出现了两次，再把所有数字做异或之后
    得到的结果和只将两个出现一次的数字做异或的结果相同
    把异或结果用二进制表示，只保留异或结果中其中的一位1，选择最靠右的即可，异或后某一位为1，
    说明原数字该位一个是1 一个是0
    
    根据这一特性可以把原数组划分成两部分，每部分中包含一个只出现一次的数字
    之后再把两部分分别异或，得到两个异或结果 就是这两个只出现一次的数字
    
    关键是怎么把那一位的结果生成出来
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int flag=0, a=0, b=0;
        vector<int> res;
        if(nums.empty())
            return res;
        for(int i=0;i<nums.size();i++)
            flag=flag^nums[i];
        flag=flag&(~flag+1);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&flag)
                a^=nums[i];
            else
                b^=nums[i];
        }
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};
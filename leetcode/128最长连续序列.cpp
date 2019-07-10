/*
    给定一个未排序的整数数组，找出最长连续序列的长度。

    要求算法的时间复杂度为 O(n)。

    示例:

    输入: [100, 4, 200, 1, 3, 2]
    输出: 4
    解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/
/*
    如果能排序的话，就比较直观了，但是要求时间复杂度是O（N），一般的排序不适用
    同时 根据官方结果来看，重复数字不增加序列长度
    要是这样的要求的话，可能要用map或者set处理
    想了一个办法，说不定可以，思路是这样的，
    先遍历一遍数组用map记录结果，
    之后逐个找数组中元素所在的最大区间，比如数组1,2,3,4,20,21,30
    数字1，找他所在的区间，向下找没有数字了，向上的连续空间可以一直找到4，区间就是[1,4]，再向后找的时候，
    2在这个区间中，跳过，记录所有找到的区间。
    这样做应该能得到结果，但是时间复杂度和空间复杂度貌似都挺高，
    还不如直接排序之后再找区间
    
    国际版评论区票数最高的的解法是一个java解法，用了hashmap 其中是这样使用hashmap的
    用hashmap在区间边界上记录区间的长度， 例如[1,2,3,4]  其中 hashmap(1)=4,hashmap(4)=4
    在向哈希表中插入元素的时候如果这个元素是一个出现过的元素则跳过，
    新元素n则判断n+1和n-1是否存在，
    1.插入hashmap(n)=hashmap(n-1)+hashmap(n+1)+1
    2.更新这一区间边界key的value，使其等于区间长度
    
    注意这里要使用unordered_map而不是map 因为unordered_map底层是hash表实现的，查找才是常数级的
    stl中的map底层应该是红黑树，查找为对数时间复杂度
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int res=0;
        for(auto num: nums)
        {
            if(m[num]==0)
            {
                int left=m[num-1]!=0?m[num-1]:0;
                int right=m[num+1]!=0?m[num+1]:0;
                int sum=left+right+1;
                res=max(res,sum);
                m[num]=sum;
                // 更新期间边界，如果left和right存在0的情况，所以不会出现错误
                m[num-left]=sum;
                m[num+right]=sum;
            }
            else
            {
                // 该值在map中存在 跳过
                continue;
            }
        }
        return res;
        
        /*
        unordered_set<int> h(nums.begin(),nums.end());
		int ans = 0;
		for(int num:nums){
			if(!h.count(num-1)){
				int temp = num;
				while(h.count(++temp));
				ans = max(ans,temp-num);
			}
		}
		return ans;
        */
    }
};
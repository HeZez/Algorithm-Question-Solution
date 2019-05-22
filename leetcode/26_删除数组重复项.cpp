class Solution {
    /*
    题目描述
    给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
    示例 1:
    给定数组 nums = [1,1,2], 
    函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
    你不需要考虑数组中超出新长度后面的元素。
    */
    /*
       我的想法 ：o(1)额外空间 那就冒泡  找到重复值把他放在最后  时间复杂度很高
       大佬的想法： 双指针第一个指针i指向不重复元素的最后一位，第二指针j顺次遍历
                    如果两个指针指向的数不同，判断i与j是否相邻  若相邻 则ij同时+1  若不相邻 将j指向的值赋给i+1， ij同时加一
     */   
public:
    int removeDuplicates(vector<int>& nums) {
        
        int len = nums.size();
        if(len < 2 )
            return len;
        int i = 0;
        int j = i +1;
        while(j < len)
        {
            if(nums[j] != nums[i])
            {
                if(i+1 != j)
                    nums[i+1] = nums[j];
                i += 1;
            }
            j += 1;
                
        }
        return i+1;
    
        /*
        if(nums.size()<=0)
            return 0;
        if(nums.size()==1)
            return 1;
        // 先遍历一遍确定不重复元素的个数
        int count=1;
        int temp=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
                count++;
        }
        for(int i=0;i<count-1; )
        {
            while(nums[i]==nums[i+1])
            {
                // 重复的放到最后
                for(int j=i+1;j<nums.size()-1;j++)
                {
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
            i++;
        }
        return count;
        */
    }
};
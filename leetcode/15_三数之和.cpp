class Solution {
    /*
        题目描述：
        给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
        注意：答案中不可以包含重复的三元组。
        例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
        满足要求的三元组集合为：
        [
          [-1, 0, 1],
          [-1, -1, 2]
        ]
    */
    /*
    方案1  暴力枚举 没啥意思
    方案2  自己想的  因为要求是等于0的数  所以要么是三个0 相加  要不然就是三个数中有正有负  把数分成正负两组
         结果是两正一负或两负一正 ，确定一正或一负，剩下的两个数用“两数之和”的方法求解
    方案3 大佬的解 先排序 接下来确定一个位置num[i]，之后在数组的后面找两个数的和是-num[i]的两个数  转化为两数之和问题
    */
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int> > result;
        vector<int> temp(3,0);
        sort(nums.begin(), nums.end());    //排序之后可以使用双指针法来进行查找，， 从两端向中间找 
        if(nums.size()<=2)
            return result;
        if(nums[0]>0||nums[nums.size()-1]<0)
            return result;
        for(int i=0;i<nums.size()-2; )
        {
            //if(nums[i]>0)     //排序之后 如果第一个数已经大于零  那么三个大于零的数是不会有等于0的结果的
            //    break;
            for(int j=i+1,k=nums.size()-1;j<k;)
            {
                if(nums[j]+nums[k]<-nums[i])
                {
                    j++;
                }
                else if(nums[j]+nums[k]>-nums[i])
                    k--;
                else
                {
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[k];
                    result.push_back(temp);
                    // 去重  由于排过序  重复的元素都是相邻的  那么再找到第一个之后 跳过后续的重复值
                    do{
                        j++;
                    }while(j<k&&nums[j-1]==nums[j]);
                    do{
                        k--;
                    }while(j<k&&nums[k+1]==nums[k]);
                }
            }
            do{
                i++;
            }while(i<nums.size()-2&&nums[i-1]==nums[i]);
        }
        return result;
    }
};
/*
    给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
    这道题第一感觉应该用树搜索类  回溯的方法，但是不太清楚怎么写
    
    大佬的解法
    1：
    “这个题蛮有意思的，可以直接从后遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集”
    2：位运算解法
    位运算的思路是这样的，n个数，可以用一个n位的二进制数来表示，每一位取0或一表示这个数取或者不取
    这样这个n位二进制数的所有情况就表示所有的子集
    大佬原话：
    “用语言描述算法真的很考验文字功底 :( 尝试着解释了一下，如下：
    数组 [1,2,3] 的子集也就是其中的三个元素取与不取的组合。把它想象为二进制的三个 bit 位 1 1 1，那么从 0 0 0 到 1 1 1       的 8 个数，就构成了所有子集的选取情况。比如 0 0 1 表示取第1个元素，0 1 1 表示取前两个元素。”
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 解法2 位运算解法
        vector<vector<int>> result;
        vector<int> subset;
        result.push_back(subset);
        if(nums.size()==0)
            return result;
        int size=nums.size();
        int subsize=1<<size;
        int hash=1;
        while(hash<subsize)
        {
            vector<int> temp;
            for(int k=0;k<size;k++)
            {
                int a=1<<k;
                if(a&hash)   //与运算之后，如果结果不等于0，说明第k个数应该在当前的这个子集里
                {
                    temp.push_back(nums[k]);
                }
            }
            result.push_back(temp);
            hash++;
        }
        return result;
    }
    /*
    //解法1
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        result.push_back(subset);
        if(nums.size()==0)
            return result;
        for(int i=0;i<nums.size();i++)
        {
            int len=result.size();
            for(int j=0;j<len;j++)
            {
                subset=result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }
        return result;
    }
    */
};
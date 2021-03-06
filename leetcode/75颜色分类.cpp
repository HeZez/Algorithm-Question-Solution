/*
    给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
    此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
    注意:
    不能使用代码库中的排序函数来解决这道题。

    示例:

    输入: [2,0,2,1,1,0]
    输出: [0,0,1,1,2,2]
    进阶：

    一个直观的解决方案是使用计数排序的两趟扫描算法。
    首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
    你能想出一个仅使用常数空间的一趟扫描算法吗？
*/

/*
    大佬的想法是，一次三路快排，在这之前也没有仔细了解过
    这一次可以更好地理解一下双路快排和三路快排
    普通的快排就是算法导论中的伪代码提到的那样， 那一种方法在数组中存在大量重复元素的时候退化严重
    双路快排是为了解决这一问题的一种改进， 把小于划分值和大于划分值的数放在数组两端，把等于划分值的值的位置空出来
    三路快排将数组划分为小于划分值，等于划分值，大于划分值的三部分
*/

class Solution {
public:
    /*
    void quickSort3(vector<int>& nums, int start, int end, int len)
    {
        int l=start-1;
        int r=end+1;
        int i=start;
        while(i<r)
        {
            if(nums[i]<1)
            {
                l++;
                swap(nums[l],nums[i]);
                i++;
            }
            else if(nums[i]>1)
            {
                r--;
                swap(nums[r],nums[i]);
            }
            else
                i++;
        }
    }
    */
    void quickSort3(vector<int>& nums, int start, int end)
    {
        int l=start-1, r=end+1;
        int i=start;
        while(i<r) // 注意这里的条件  
        {
            // 由于题中只有三个数，而且我们知道中间的那个数是1
            // 所以使用1作为partition值
            if(nums[i]<1)
            {
                swap(nums[i], nums[++l]);
                i++;
            }
            else if(nums[i]>1)
            {
                swap(nums[i], nums[--r]);
            }
            else
                i++;
        }
    }
    void sortColors(vector<int>& nums) {
        
        int len=nums.size();
        if(len<=1)
            return ;
        quickSort3(nums, 0, len-1);
    }
};
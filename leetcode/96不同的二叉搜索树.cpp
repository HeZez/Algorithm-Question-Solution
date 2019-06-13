/*
    
    题目描述：
    给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

    示例:

    输入: 3
    输出: 5
    解释:
    给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3

       解法 1. 动态规划 m[i:j]表示i到j的数二叉搜索树个数 于是m[1:n]=m[1:1]*m[2:n]+m[1:2]*m[3:n]+...+m[1:n-1]*m[n:n] 
         
*/

class Solution {
public:
    int numTrees(int n) {
        // 处理特殊情况
        if(n==0||n==1)
        {
            return n==0?0:1;
        }
        if(n==2)
            return 2;
        int *nums = new int[n+1];
        nums[0]=1;
        for(int i=1;i<=n;i++)
        {
            nums[i]=0;
            for(int j=0;j<i;j++)
                nums[i]+=nums[j]*nums[i-j-1];
        }
        return nums[n];
    }
    
  /* 
public:
    int numTrees(int n) {
        // 处理特殊情况
        if(n==0||n==1)
        {
            return n==0?0:1;
        }
        int result=0;
        int *nums = new int[n];
        //构造数组
        for(int i=0;i<n;i++)
            nums[i]=i+1;
        
        
        for(int i=0;i<n;i++)
        {
            if(i==0||i==n-1)
            {
                if(i==0)
                {
                    result+=1+numSubTrees(nums, 1,n-1);
                    cout<<i<<":"<<result<<endl;
                }
                else
                {
                    result+=1+numSubTrees(nums, 0,n-2);
                    cout<<i<<":"<<result<<endl;
                }
            }
            else
            {
                result+=1+(numSubTrees(nums, 0,i-1)+numSubTrees(nums, i+1,n-1));
                cout<<i<<":"<<result<<endl;
            }
        }
        return result;
    }
    
    int numSubTrees(int* num, int left, int right)
    {
        int result=0;
        if(left==right)
            return 0;
        if(left>right)
            return 0;
        for(int i=left;i<=right;i++)
        {
            if(i==left||i==right)
            {
                if(i==left)
                    result+=1+numSubTrees(num, left+1,right);
                else
                    result==1+numSubTrees(num, left,right-1);
            }
            else
                result+=1+(numSubTrees(num, left,i-1)+numSubTrees(num, i+1,right));
        }
        return result;
    }
    */
    
};
/*
    给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
    
    示例:
    输入: n = 4, k = 2
    输出:
    [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
    ]
*/

class Solution {
private:
    void combineCore(int i, int k, int n, vector<int>& temp)
    {
        // 递归边界 
        if(temp.size()==k)
        {
            
            result.push_back(temp);
            return ;
        }
        int nums=temp.size();
        for(int j=i;j<=n;j++)
        {
            if(k-temp.size() > n-j+1)
                break;
            temp.push_back(j);
            combineCore(j+1, k, n, temp);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        if(k>n)
            return result;
        vector<int> temp;
        combineCore(1, k, n, temp);

        return result;
    }
};
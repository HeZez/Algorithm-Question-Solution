/*
    给出一个区间的集合，请合并所有重叠的区间。

    示例 1:

    输入: [[1,3],[2,6],[8,10],[15,18]]
    输出: [[1,6],[8,10],[15,18]]
    解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
    示例 2:

    输入: [[1,4],[4,5]]
    输出: [[1,5]]
    解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/
/*
    自己想到的办法就是排序之后遍历
*/
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)       // 比较函数要求是静态的
    {
        // 这里注意 当前一个区间前半部分相同时比较后半部分以保证正确的排序
        if(a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len=intervals.size();
        vector<vector<int>> result;
        vector<int> temp;
        if(len<=1)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);
        for(int i=1;i<len;i++)
        {
            if(intervals[i][0]>temp[1])
            {
                result.push_back(temp);
                temp.pop_back();
                temp.pop_back();
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                if(i==len-1)
                    result.push_back(temp);     // 不要忘了最后一个区间
            }
            else
            {
                if(temp[1]<=intervals[i][1])
                    temp[1]=intervals[i][1];    // 注意[[1,4],[2,3]]这种包含的情况
                if(i==len-1)
                    result.push_back(temp);     // 不要忘了最后一个区间
            }
        }
        return result;
    }
};
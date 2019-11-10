/*
        你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

    假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

    你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

    示例:

    给定 n = 5，并且 version = 4 是第一个错误的版本。

    调用 isBadVersion(3) -> false
    调用 isBadVersion(5) -> true
    调用 isBadVersion(4) -> true

    所以，4 是第一个错误的版本。 
*/

/*
    递归二分找边界
    这里有一个二分时求中间值的技巧
    如果用(l+r)/2 如果l和r都很大 二者相加会越界
    应该用l+(r-l)/2
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
private: int result=0;
public:
    int firstBadVersion(int n) {
        firstBadVersionCore(1, n);
        return result;
    }
    void firstBadVersionCore(int l, int r)
    {
        //
        int middle=l+(r-l)/2;
        bool res;
        if(l==r)
        {
            if(isBadVersion(l))
                result=l;
            else
                result=l+1;
        }
        else if(l<r)
        {
            res=isBadVersion(middle);
            if(res)
                firstBadVersionCore(l,middle);
            else
                firstBadVersionCore(middle+1,r);
        }
        
    }
};
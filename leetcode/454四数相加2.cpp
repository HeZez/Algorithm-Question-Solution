/*
    给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

    为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

    例如:

    输入:
    A = [ 1, 2]
    B = [-2,-1]
    C = [-1, 2]
    D = [ 0, 2]

    输出:
    2

    解释:
    两个元组如下:
    1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
    2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

/*

*/

// 大佬自己实现的hash map
const int N=360007;
class Hash
{
int keys[N]={0}, values[N]={0};
public:
    Hash(){
        memset(values, 0, sizeof(values));
    }
    int& operator [](int n){
        int idx = (n%N + N)%N, cnt=1;
        while(keys[idx]!=n && values[idx]!=0){
            idx = (idx+cnt*cnt)%N;
            cnt += 1;
        }
        keys[idx] = n;
        return values[idx];
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        //unordered_map<int, int> um;
        Hash um;
        int res=0;
        
        for(auto i: A)
        {
            for(auto j: B)
            {
                um[i+j]++;
            }
        }
        for(auto i: C)
        {
            for(auto j: D)
            {
                res+=um[-(i+j)];
            }
        }
        
        /*
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
            {
                um[A[i]+B[j]]++;
            }

        for(int i=0;i<C.size();i++)
            for(int j=0;j<D.size();j++)
            {
                res+=um[-(C[i]+D[j])];
            }
        */
        return res;

    }
};
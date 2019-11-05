/*
    给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。

    h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）至多有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）”



    示例:

    输入: citations = [3,0,6,1,5]
    输出: 3 
    解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
         由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。


    说明: 如果 h 有多种可能的值，h 指数是其中最大的那个。
*/

/*
    这题对h指数的翻译有问题 原文如下
    According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers  have at least h citations each, and the other N − h papers have no more than h citations each."
    h是N篇论文里至少有h篇有h个引用，其他的N-h篇不超过h
    
    我个人的思路是先排序，之后倒着遍历
    从后向前移动指针的时候记录已经遍历过的元素个数，分几种情况讨论
    如果遍历元素数小于当前指向元素，继续向前遍历
    如果遍历元素数等于当前指向元素，找到h指数
    如果遍历元素数大于当前指向元素，h指数为遍历元素个数减一
    
    一种特殊情况是 如果最小的引用数也比文章总数大，那么h指数就是文章总数
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()<1)
            return NULL;
        sort(citations.begin(), citations.end());
        int count=0;
        // 特殊的情况
        if(citations[0]>citations.size())
            return citations.size();
        
        for(int i=citations.size()-1;i>=0;i--)
        {
            count++;
            if(count<citations[i])
                continue;
            else if(count>citations[i])
            {
                count--;
                break;
            }
            else
                break;
                
        }
        return count;
    }
};
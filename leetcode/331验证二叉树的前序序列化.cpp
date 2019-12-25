/*
    序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
    例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。

    给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

    每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。

    你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。

    示例 1:
    输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
    输出: true

    示例 2:
    输入: "1,#"
    输出: false

    示例 3:
    输入: "9,#,#,1"
    输出: false
*/
/*
    这道题要求不重建树， 一般情况来说 只有前序遍历结果是无法准确重建二叉树的
    不过这道题给出的遍历结果中是包含null位置的  这样的改变意味着什么？
    问题的关键可能就在这些NULL出现的位置是否正确上

    还是想不到啊 看了看评论 有用出入度来判断的 也有用栈的 
    我认为的一个比较好的解释是这样的 来自国外版的leetcode
    因为这是一个先序遍历
    首先如果一颗二叉树存在，则一定存在一个树根，这个树根提供了两个空位，也就是左孩子和右孩子的位置
    如果是一个#，那么意味着空位被占了一个，空位数减一
    如果是一个正常的值，这个值占用了一个位置，但是这个值的节点又提供了两个位置，合计空位加一

    如果在整个序列没有完成遍历的时候，空位数就已经为0了，后面却还有内容需要额外的空位，那么这个序列就不是一棵树
    在遍历完成后，检查空位数是否被全部用完，全部用完的话，说明这个序列是一颗二叉树
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        // 这里可以不用split来处理 直接判断字符来对结果进行加减也是可以的 这里联系一下split的写法
        int result=1;   // 初始值是1 初始根节点加入后空位应该为2 但是我们的策略是加入非空节点空位数+1 所以相当于最开始自带一个空位
        /*
        for(int i=0;i<preorder.size();i++)
        {
            if(result==0)
                return false;
            if(preorder[i]==',')
                continue;
            if(preorder[i]=='#')
                result--;
            else
            {
                result++;
                while(i<preorder.size() && preorder[i]!=',')
                    i++;
            }
        }
        */
        vector<string> tokens;
        splitCore(preorder, tokens, ",");
        for(auto item: tokens)
        {
            if(result==0)
                return false;
            if(item=="#")
                result--;
            else
                result++;
        }
        return result==0;
    }
    void splitCore(string preorder, vector<string>& result, string delimiters )
    {
        // 练习一下split的写法  size_type类型 c++中用来存贮 string vector对象的长度
        string::size_type lastPos=preorder.find_first_not_of(delimiters, 0);
        string::size_type pos=preorder.find_first_of(delimiters, lastPos);
        while(string::npos!=lastPos || string::npos!=pos)    // string::npos 是一个参数 表示不存在的位置
        {
            result.push_back(preorder.substr(lastPos, pos-lastPos));
            lastPos=preorder.find_first_not_of(delimiters, pos);
            pos=preorder.find_first_of(delimiters, lastPos);
        }
    }
};
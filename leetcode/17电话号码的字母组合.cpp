/*
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
    给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


    示例:
    输入："23"
    输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    说明:
    尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/
/*
    自己的想法，可以用一个map存每个数字的字符串，
    之后根据给的数字字符串 按照数字的顺序将字母存到vector中，之后利用树搜索的方式构造解
*/
class Solution {
private:
    void letterCombinationsCore(vector<string>& treeNode, int index, string temp) 
    {
        // 递归边界
        if(index==treeNode.size()-1)
        {
            for(int i=0;i<treeNode[index].size();i++)
            {
                temp+=treeNode[index][i];
                result.push_back(temp);
                temp.pop_back();
            }
            return ;
        }
        for(int i=0;i<treeNode[index].size();i++)
        {
            temp+=treeNode[index][i];
            letterCombinationsCore(treeNode, index+1, temp);
            temp.pop_back();
        }
    }
    
public:
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        if(digits.size()<=0)
            return result;
        map<char, string> m;
        vector<string> treeNode;
        string temp="";
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        for(int i=0;i<digits.size();i++)
        {
            treeNode.push_back(m[digits[i]]);
        }
        letterCombinationsCore(treeNode, 0, temp);
        return result;
    }
};
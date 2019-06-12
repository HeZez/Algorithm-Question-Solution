/*
    给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
    示例:

    输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
    输出:
    [
      ["ate","eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]
    说明：

    所有输入均为小写字母。
    不考虑答案输出的顺序。

*/
/*
    自己的想法，用一个map记录第一个单词的所有字母，之后把这个词从原来的集合中去掉，
    遍历整个数组，如果和第一个词是异位词就加到结果中，在原数组中删掉这个词
    直到原数组为空 这么做感觉会很慢
    
    评论区大佬： 在美版leetcode上看到大神的思路，用质数表示26个字母，把字符串的各个字母相乘，这样可保证字母异位词的乘积必定是相等的。其余步骤就是用map存储，和别人的一致了。（这个用质数表示真的很骚啊！！!）
    
    更进一步，需要设计一个方法，让异位词映射到同样的哈希值上，这样就可以将其分开
    
    还有其他的很多方法，去国外的leetcode上看了看，官方的题解和评论区都不是国内的能比的，是一个很好的学习途径
    官方给了两个解法
        1. 对字符串进行排序，比如 cba和bca排序后的结果都是abc 以此进行判断
        2. 统计字母个数，用一个26位的数组来表示一个单词中每个字母出现的次数，以此进行判断
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.empty())
            return result;
        // 大佬的代码中用了unordered_map  需要再详细的了解一下这个容器
        unordered_map<string, vector<string>> mp;
        string temp;
        for(int i=0;i<strs.size();i++)
        {
            temp=strs[i];
            // 先排序
            sort(temp.begin(), temp.end());
            // 之后用排序后的结果作为key
            mp[temp].push_back(strs[i]);
        }
        
        // c++11中的auto关键字可以自动判断变量类型
        for(auto p: mp)
            result.push_back(p.second);
        return result;
    }
};
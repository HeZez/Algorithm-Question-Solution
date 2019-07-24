/*
    给定两个字符串 s 和 t，判断它们是否是同构的。

    如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

    所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

    示例 1:
    输入: s = "egg", t = "add"
    输出: true
    
    示例 2:
    输入: s = "foo", t = "bar"
    输出: false
    
    示例 3:
    输入: s = "paper", t = "title"
    输出: true
    说明:
    你可以假设 s 和 t 具有相同的长度。
*/
/*
    题目的意思就是能不能映射的过来，也就是一个字母在一次转换中只能有一映射值
    比如实例2 
    foo
    bar
    字符o无法同时映射到a和r，所以无法转换
    根据这个思路，可以用一个hash表来记录映射结果
    如果出现矛盾就false
    
    在测试用例中还出现了
    ab
    aa     false
    这样的样例
    这说明s到t的映射有这样的要求 
    1.s中的不同字符不能映射到到同一个字符上
    2.s中同一个字符不能映射到不同的字符上
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> KV;
        unordered_map<char, char> VK;
        // 题目中给出提示，可以认为两个字符串长度相同
        for(int i=0;i<s.size();i++)
        {
            if(KV.find(s[i])==KV.end())
            {
                KV[s[i]]=t[i];
                if(VK.find(t[i])==VK.end())
                {
                    KV[s[i]]=t[i];
                    VK[t[i]]=s[i];
                }
                else
                {
                    // 这说明s中有不同字符映射到了同一个字符
                    return false;
                }
            }
            else
            {
                // s中相同字符映射到了不同字符上
                if(KV[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};
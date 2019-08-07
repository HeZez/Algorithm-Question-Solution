/*
    以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

    示例 1：

    输入："/home/"
    输出："/home"
    解释：注意，最后一个目录名后面没有斜杠。
    示例 2：

    输入："/../"
    输出："/"
    解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
    示例 3：

    输入："/home//foo/"
    输出："/home/foo"
    解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
    示例 4：

    输入："/a/./b/../../c/"
    输出："/c"
    示例 5：

    输入："/a/../../b/../c//.//"
    输出："/c"
    示例 6：

    输入："/a//b////c/d//././/.."
    输出："/a/b/c"
*/

/*
    一个.表示当前目录本身，..表示向上返回一级目录
    根目录无法返回上一级
    
    首先就是规范化整个字符串，先扫描一遍，去掉多余的斜杠
    /.: 直接全部去掉，之后再检验一下，如果不是/开头，在路径头加一个斜杠
    
    看了大佬的写法，自己傻的真实
    先把所有路径的用/分隔开的得到一个字符串序列，之后把这些入栈，
    遇到“..”就弹出栈顶
    遇到“.”跳过
    
*/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathSplit;
        string temp="";
        vector<string> s1;   // 用vector模拟栈操作， 因为最后取数据的时候要从栈底开始取
        // 这里用一个bool变量来记录最后一个路径元素有没有被加入到pathSplit中
        bool flag=false;
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                if(!temp.empty())
                    pathSplit.push_back(temp);
                temp="";
                flag=false;
                continue;
            }
            else
            {
                
                temp+=path[i];
                flag=true;
            }
        }
        if(flag)
            pathSplit.push_back(temp);
        
        string res="";
        /*
        for(auto it: pathSplit)
            cout<<it<<endl;
            */
        
        for(auto it: pathSplit)
        {
            if(it=="..")
            {
                // 这里注意不合理的..操作  s1有可能是空的
                if(s1.empty())
                    continue;
                else
                    s1.pop_back();
            }
            else if(it==".")
                continue;
            else
                s1.push_back(it);
        }
        for(auto it: s1)
        {
            res+='/';
            res+=it;
        }

        return res.empty()? "/":res;
    }
};
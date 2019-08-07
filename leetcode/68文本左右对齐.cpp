/*
    给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

    你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

    要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

    文本的最后一行应为左对齐，且单词之间不插入额外的空格。

    说明:

    单词是指由非空格字符组成的字符序列。
    每个单词的长度大于 0，小于等于 maxWidth。
    输入单词数组 words 至少包含一个单词。
    示例:

    输入:
    words = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth = 16
    输出:
    [
       "This    is    an",
       "example  of text",
       "justification.  "
    ]
    示例 2:

    输入:
    words = ["What","must","be","acknowledgment","shall","be"]
    maxWidth = 16
    输出:
    [
      "What   must   be",
      "acknowledgment  ",
      "shall be        "
    ]
    解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
         因为最后一行应为左对齐，而不是左右两端对齐。       
         第二行同样为左对齐，这是因为这行只包含一个单词。
    示例 3:

    输入:
    words = ["Science","is","what","we","understand","well","enough","to","explain",
             "to","a","computer.","Art","is","everything","else","we","do"]
    maxWidth = 20
    输出:
    [
      "Science  is  what we",
      "understand      well",
      "enough to explain to",
      "a  computer.  Art is",
      "everything  else  we",
      "do                  "
    ]
*/
/*
    贪心排列单词，先扫描单词长度，尽可能的放到一行里
    先确定每一行要放哪些单词，之后分配空格
    最后一行左对齐
    
    分配空格的原则：
    空格数共x个，单词间有y个间隔
    
    代码写的又臭又长
*/
    
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string temp="";
        int numPerLine=0;
        int lengthPerLine=0;
        int lastLineNum=0;  //记录一下最后一行的单词数
        // 这个循环里没有处理最后一行
        for(int i=0;i<words.size(); )
        {
            lengthPerLine+=words[i].size();
            if(lengthPerLine+numPerLine<=maxWidth)
            {
                numPerLine++;
                i++;
                if(i>=words.size())
                   lastLineNum=numPerLine;
            }
            else
            {
                lengthPerLine-=words[i].size();  // 最新的这个单词不应该被放到这一行
                // 计算空格数
                /*
                    每个位置基准的空格数为(maxWidth-lengthPerLine)/(numPerLine-1)
                    之后(maxWidth-lengthPerLine)%(numPerLine-1)为有几个空格需要多加一个长度
                */
                int blankLength=0;
                int plusOne=0;
                if(numPerLine-1>0)
                {
                    blankLength=(maxWidth-lengthPerLine)/(numPerLine-1);
                    plusOne=(maxWidth-lengthPerLine)%(numPerLine-1);
                }
                // 这里把每行一个单词和多个单词的情况分开吧
                if(numPerLine==1)
                {
                    temp+=words[i-1];
                    int t=maxWidth-words[i-1].size();
                    while(t>0)
                    {
                        temp+=' ';
                        t--;
                    }
                }
                else
                {
                    for(int j=i-numPerLine;j<i;j++)
                    {
                    if(j!=i-1)
                    {
                        temp+=words[j];
                        if(plusOne>0)
                        {
                            for(int k=0;k<blankLength+1;k++)
                                temp+=' ';
                            plusOne--;
                        }
                        else
                        {
                            for(int k=0;k<blankLength;k++)
                                temp+=' ';
                        }
                    }
                    else
                    {
                        temp+=words[j];
                    }
                    }
                }
                res.push_back(temp);
                // 重置参数
                temp="";
                numPerLine=0;
                lengthPerLine=0;
            }
        }
        
        // 处理最后一行
        temp="";
        numPerLine=0;
        lengthPerLine=0;
        for(int i=words.size()-lastLineNum;i<words.size();i++)
        {
            if(i!=words.size()-1)
            {
                temp+=words[i];
                temp+=' ';
                lengthPerLine+=(words[i].size()+1);
            }
            else
            {
                temp+=words[i];
                lengthPerLine+=(words[i].size());
            }
        }
        
        // 把空格补全
        int lastBlank=maxWidth-lengthPerLine;
        for(int i=0;i<lastBlank;i++)
            temp+=' ';
            
        res.push_back(temp);
        
        return res;
    }
};
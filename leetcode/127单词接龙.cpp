/*
    给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
    每次转换只能改变一个字母。
    转换过程中的中间单词必须是字典中的单词。
    说明:

    如果不存在这样的转换序列，返回 0。
    所有单词具有相同的长度。
    所有单词只由小写字母组成。
    字典中不存在重复的单词。
    你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
    示例 1:

    输入:
    beginWord = "hit",
    endWord = "cog",
    wordList = ["hot","dot","dog","lot","log","cog"]

    输出: 5

    解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
         返回它的长度 5。
    示例 2:

    输入:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log"]

    输出: 0
    解释: endWord "cog" 不在字典中，所以无法进行转换。
*/

/*
    DFS回溯 关键是如何判断其中是否包含只差一位的单词
    我认为的回溯解法，可以找到全部的接龙解，但是会超时
    
    大佬的解法是BFS 广搜（确实应该是个广搜，相当于找到叶子节点路径最短的路径）
    大佬给出的解法，寻找差一位的方法也比较暴力 = =
    大佬的方法是用一个队列来存储只相差一个字母的单词，
    之后一次循环处理队列中与上一个单词差一位的单词，再把这次循环中处理的单词的邻居加入到队列中，
    这样一旦找到目标词，就是最短的接龙结果
    不过单纯的这样处理，也会超时
    
    为了进一步优化时间复杂度，大佬从两端同时开始向中间找，并且用两个指针，去找较小的那一个
    详细看代码
*/
class Solution {
public:
    /*
    // 这种简单的回溯可以得到结果，但是在一些情况会超时
    int res=INT_MAX;
    //vector<vector<string>> results;
    void ladderLengthCore(string beginWord, string& endWord, vector<string>& wordList, vector<string> temp)
    {
        // 递归边界
        if(beginWord==endWord)
        {
            //results.push_back(temp);
            int resTemp=temp.size();
            res=min(res, resTemp);
            return ;
        }
        if(temp.size()>res)
            return ; //剪枝
        for(int i=0; i<wordList.size(); i++)
        {
            int flag=0;
            for(int j=0;j<wordList[i].size();j++)
            {
                if(beginWord[j]!=wordList[i][j])
                    flag++;
            }
            if(flag==1)
            {
                // 回溯开始
                string s=wordList[i];
                temp.push_back(s);
                wordList.erase(wordList.begin()+i);
                ladderLengthCore(s, endWord, wordList, temp);
                wordList.insert(wordList.begin()+i, s);
                temp.pop_back();
            }   
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> temp;
        temp.push_back(beginWord);
        ladderLengthCore(beginWord,  endWord,  wordList, temp);
        return res==INT_MAX? 0 : res;
    }
    */
    
    
    // 大佬的解法
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *pHead, *pTail;
        if(dict.find(endWord)==dict.end())
            return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int res=2;
        while(!head.empty()&&!tail.empty())
        {
            //在小的那部分中搜索
            if(head.size()<tail.size())
            {
                pHead=&head;
                pTail=&tail;
            }
            else
            {
                pHead=&tail;
                pTail=&head;
            }
            unordered_set<string> temp;
            for(auto it=pHead->begin(); it!=pHead->end();it++)
            {
                string word=*it;
                for(int i=0;i<word.size();i++)
                {
                    char t=word[i];
                    for(int j=0;j<26;j++)
                    {
                        word[i]='a'+j;
                        if(pTail->find(word)!=pTail->end())
                            return res;
                        if(dict.find(word)!=dict.end())
                        {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i]=t;
                }
            }
            res++;
            pHead->swap(temp);
        }
        return 0;
    }
    
};
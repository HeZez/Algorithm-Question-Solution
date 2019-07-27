/*
    实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

    示例:

    Trie trie = new Trie();

    trie.insert("apple");
    trie.search("apple");   // 返回 true
    trie.search("app");     // 返回 false
    trie.startsWith("app"); // 返回 true
    trie.insert("app");   
    trie.search("app");     // 返回 true
    说明:

    你可以假设所有的输入都是由小写字母 a-z 构成的。
    保证所有输入均为非空字符串。
*/
/*
  什么是前缀树？ 看样例没太看懂  
  看了一下解释，大概明白什么意思了，把字符串的各个字符拆开，然后按树形结构存储
  相同位置上出现过的字符不重复存储，比如 cook和code  这两个单词前两位co是相同的
  在树形结构中就是co部分共享一条路径，ok和de 是分开的
  
  我在写的时候记录next用了hashmap 感觉没有那些用next[26]数组的时间效率高
*/
class TrieNode
{
public:
    bool isEnd;  // 用来标识当前节点是否是一个单词的结尾
    char c;  // 当前节点字符
    unordered_map<char, TrieNode*> next;  // 记录下一个字符
    // 初始化
    TrieNode(bool state, char ch)
    {
        c=ch;
        isEnd=state;
        // unordered_map<char, TrieNode*> next;  // 记录下一个字符
    }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode(false, '/');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if( temp->next.find(word[i])!=temp->next.end() )
            {
                temp=temp->next[word[i]];
                if(i==word.size()-1)
                    temp->isEnd=true;
            }
            else
            {
                bool isEnd=false;
                if(i==word.size()-1)
                    isEnd=true;
                TrieNode* newNode=new TrieNode(isEnd, word[i]);
                temp->next[word[i]]=newNode;
                temp=temp->next[word[i]];
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if( temp->next.find(word[i])!=temp->next.end() )
            {
                temp=temp->next[word[i]];
            }
            else
            {
                return false;
            }
        }
        return temp->isEnd?true:false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if( temp->next.find(prefix[i])!=temp->next.end() )
            {
                temp=temp->next[prefix[i]];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
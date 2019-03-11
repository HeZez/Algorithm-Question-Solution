/*
    题目描述
    请实现一个函数，将一个字符串中的每个空格替换成“%20”。
    例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
/*
    如果顺序扫描，再逐个向后移动，时间复杂度过大
    可以先扫描一遍字符串，看一下一共有多少个空格
    题中要求将空格替换为%20 ，顺便一提 这样的要求应该是某些应用场景要求的，比如在网络编程里URL参数含有特殊字符可能出现错误
    得到空格数之后，替换后的字符串长度=原长度+2 * 空格数
    之后用两个指针，一个指向新字符串尾部，一个指向原字符串尾部，从原字符串尾部向前遍历
    普通字符复制到新字符串，是空格新字符串就以此设置字符为0 2 %
*/
class Solution {
public:
    //注意字符串末尾有'\0'
	void replaceSpace(char *str,int length) {
        int flag=0;
        int num=0;
        int newLength=0;
        if(length>0)
        {
            while(str[num]!='\0')
            {
                if(str[num]==' ')
                    flag++;
                num++;
            }
            newLength=num+flag*2;
            while(num>=0)
            {
                if(str[num]!=' ')
                {
                    str[newLength--]=str[num];
                }
                else
                {
                    str[newLength--]='0';
                    str[newLength--]='2';
                    str[newLength--]='%';
                }
                num--;
            }
        }
	}
};
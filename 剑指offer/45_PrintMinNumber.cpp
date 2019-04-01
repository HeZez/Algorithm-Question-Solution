/*
    题目描述
    输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
    例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

/*
    我们的目的是想要重新制定一个排序规则，来将整个数组排序，排序后的结果直接组合就是答案
    因为手写快排有些难度，所以这里先用冒泡排序代替一下
    排序规则：例如m,n两个数字， 组合成一个数字有两种情况，mn和nm，如果mn<nm，则在我们的排序规则中m是小于n的
    目的就是根据我们自己制定的排序规则来把数组中的数字排序
    之后直接组合城字符串代表的就是最小的数字，这里使用字符串是因为可能出现大数的情况
    至于为什么这样得到的结果就是最小的数，详细证明在剑指offer第229页给出
    从自反性、对称性和传递性三个方面给出了证明
*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> sList=Order(numbers);
        string result;
        for(int i=0;i<sList.size();i++)
            result+=sList[i];
        return result;
    }
    
private:
    vector<string> Order(vector<int> numbers)
    {
        int length=numbers.size();
        string str;
        vector<string> result;
        // 先把整数转成字符串 c++的string类中包含这样的方法
        for(int i=0;i<length;i++)
        {
            str=to_string(numbers[i]);
            result.push_back(str);
        }
        // 一个冒泡排序 可以替换为快速排序 ，时间复杂度更低
        for(int i=0;i<length;i++)
        {
            for(int j=i+1;j<=length-1;j++)
            {
                if(isS1BiggerThanS2(result[i],result[j]))
                    swap(result[i], result[j]);
            }
        }
        return result;
    }
    bool isS1BiggerThanS2(string s1, string s2)
    {
        string temp1,temp2;
        temp1=s1+s2;
        temp2=s2+s1;
        bool result=false;
        // 比较两个字符串的大小， c++中可以这样比较或者使用conpare()函数
        if(temp1>=temp2)
            result=true;
        return result;
    }
};
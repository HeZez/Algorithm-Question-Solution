/*
    给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
    示例 1:

    输入: num1 = "2", num2 = "3"
    输出: "6"
    示例 2:

    输入: num1 = "123", num2 = "456"
    输出: "56088"
    说明：

    num1 和 num2 的长度小于110。
    num1 和 num2 只包含数字 0-9。
    num1 和 num2 均不以零开头，除非是数字 0 本身。
    不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

/*
    注意 '0'的ascii码是48
    vector的insert方法可以在指定位置插入元素
    评论区中大佬给出的解题思路
    num1的第i位(高位从0开始)和num2的第j位相乘的结果在乘积中的位置是[i+j, i+j+1]
        例: 123 * 45,  123的第1位 2 和45的第0位 4 乘积 08 存放在结果的第[1, 2]位中
          index:    0 1 2 3 4  
              
                        1 2 3
                    *     4 5
                    ---------
                          1 5       ->3*5=15  3和5都是第0位 i+j=0,i+j+1=1于是15在0和1两位上
                        1 0
                      0 5
                    ---------
                      0 6 1 5
                        1 2
                      0 8
                    0 4
                    ---------
                    0 5 5 3 5
        这样我们就可以单独都对每一位进行相乘计算把结果存入相应的index中     
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        // 先判断一下特殊情况 如果两个数中有一个是零，则返回“0”
        if(num1[0]=='0'||num2[0]=='0')
            return "0";
        int len1=num1.size();
        int len2=num2.size();
        int carayNum=0;   // 进位 
        int* mul=new int[len1+len2];
        // 给mul这个数组赋值 全是0
        for(int i=0;i<len1+len2;i++)
        {
            mul[i]=0;
        }
        //int result=num1[0]-48+num2[0]-48;
        string result="";
        int temp=0;
        for(int i=len1-1; i>=0; i--)
        {
            for(int j=len2-1; j>=0; j--)
            {
                temp=(num1[i]-48)*(num2[j]-48);
                temp+=mul[i+j+1];  
                mul[i+j]+=temp/10;          //这个值的加和是会超过10 的 但是没关系
                mul[i+j+1]=temp%10;         // 因为在接下来迭代的时候i+j这个位置就会对10取余
                
            }
        }
        // mul中第一个不是0的数直到最后一位
        int pos=0;
        while(mul[pos]==0&& pos<len1+len2)
        {
            pos++;
        }
        for(int j=pos;j<len1+len2;j++)
        {
            result += (char)(mul[j]+48);
        }
        return result;
    }
};
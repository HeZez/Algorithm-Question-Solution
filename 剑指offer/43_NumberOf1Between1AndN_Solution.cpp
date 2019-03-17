/*
    题目描述
    求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
    为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
    ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/
class Solution {
public:
    /*
    //一： 暴力穷举
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count=0;
        if(n<1) return 0;
        for(int i=1;i<=n;++i)
            {
            int temp=i;
            while(temp)
                {
                if(temp%10==1)
                    ++count;
                temp/=10;
            }
        }
        return count;
    }
    */
    
    // 第二种方法 找规律
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count=0;
        if(n<1) 
            return 0;
        int i=1;  // 表示具体位数，等于1为个位 等于10为十位 以此类推
        int cur,after,before=0;  // cur为当前位上的数字，如果12345 当前位为第三位 cur=3 befor=12 after=45
        while((n/i)!=0)
        {
            cur=(n/i)%10;
            before=n/(i*10);
            after=n%i;
            /*
                这里有三种情况
                1.当前位为0 在这一位上出现1的次数为before*i 例如12 0 45 第三位出现1次数应为12*100
                2.当前位为1 这一位上出现1的次数为before*i+after+1 例如12 1 45  因为12*100 +45 +1  
                    要+1是因为数量的原因  比如 1 01 after=1 百位出现1的情况有1 00，1 01这么两次 
                3.当前位大于1 这一位出现1的个数为（before+1）*i 12 2 45  百位出现1的次数为（12+1）*100
            */
            if(cur==0)
                count+=before*i;
            else if(cur==1)
                count+=(before*i+after+1);
            else
                count+=(before+1)*i;
            i*=10;  //前进一位
        }
        return count;
    }

};
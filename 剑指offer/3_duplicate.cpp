class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    /*
    题目描述
    在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
    数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
    例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
    */
    /*
    问题的关键在于一个长度为n的数组，数字范围在0到n-1之间，如果数组中没有重复元素，那么将这些数字排序后数字与下标应该相同，
    如果存在重复的数字这种情况不存在，所以可以逐个将当前数字与其对应下标的数字交换，直到当前数字等于下标，
    如果出现了两个交换的数字相同的情况，说明该数字重复
    */
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers==nullptr||length<=0)
            return false;
        for(int i=0;i<length;i++)  // 判断数组内的数是否全部符合要求
        {
            if(numbers[i]<0||numbers[i]>length-1)
                return false;
        }
        bool result=false;
        int temp;
        int i=0;
        
        while(i<length)
        {
            if(numbers[i]!=i)
            {
                if(numbers[numbers[i]]==numbers[i])
                {
                    result=true;
                    *duplication=numbers[i];
                    break;    //找到了就退出循环
                }
                temp=numbers[i];
                numbers[i]=numbers[temp];
                numbers[temp]=temp;
            }
            else
                i++;
        }
        
        return result;
    }
};
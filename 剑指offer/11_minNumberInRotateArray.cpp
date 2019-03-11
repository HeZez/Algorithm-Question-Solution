/*
    题目描述
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
    输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
    NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
/*
    二分 ，看中间的数字和两端数字的大小关系，如果前段数字小于中间数字，最小数在后半段，否则在前半段
    值得注意的是，这个数组之前虽然是升序排列的，但是有可能有重复元素，所以可能出现中间位置与两端的数字都相等的情况
    这种情况要用顺序查找解决
*/
class Solution {
public:
    
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left=0;
        int right=rotateArray.size()-1;
        int mid=0;
        if(rotateArray.size()==0)
            return 0;
        while(rotateArray[left]>=rotateArray[right])
        {
            if(right-left==1)
            {
                mid=right;
                break;
            }
            mid=(right+left)/2;
            //mid=left+(right-left)/2;
            if(rotateArray[mid]==rotateArray[left]&&rotateArray[mid]==rotateArray[right])  // 三个数相同 采用顺序搜索的方式
                return orderSearch(rotateArray,left,right);
            if(rotateArray[left]<=rotateArray[mid])      // 注意这里的大小关系
                left=mid;
            else
                right=mid;
        }
        return rotateArray[mid];
    }
private:
    int orderSearch(vector<int> rotateArray,int left,int right)
    {
        int result=rotateArray[left];
        for(int i=left;left<right;i++)
        {
            if(rotateArray[i]>rotateArray[i+1])
                result=rotateArray[i+1];
        }
        return result;
    }
    
};
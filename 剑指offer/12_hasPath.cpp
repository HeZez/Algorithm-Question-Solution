/*
    题目描述
    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
    路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
    如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
    例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
    但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/
class Solution {
/*
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL||str==NULL)
            return false; 
        bool* visited=new bool[rows*cols];   //一个和原矩阵一样大的数组来记录一个元素是否被访问过
        bool result=false;
        memset(visited,0,rows*cols);
        int strLength=0;   // 用来记录字符串的下标移动
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i*cols+j]==str[strLength])
                     result=hasPathCore(matrix,rows,cols,i,j,str,strLength,visited);
                if(result)
                {
                    return result;
                }
                    //return result;
            }
        }
        delete[] visited;
        cout<<str[0]<<endl;
        return result;
    }
private:
    bool hasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int strLength, bool* visited)
    {
        // 参数说明matrix矩阵 rows矩阵行数 cols矩阵列数 row当前所在行 col当前所在列 str要匹配字符串的头指针 strLength当前是第几个字符
        // visited记录每个位置是否被访问过
        bool result;
        strLength++;
        visited[row*cols+col]=1;
        if(str[strLength]=='\0')
            return true;
        if(row-1>=0&&(visited[(row-1)*cols+col]==0)&&matrix[(row-1)*cols+col]==str[strLength])
        {
            hasPathCore(matrix,rows,cols,row-1,col,str,strLength, visited);
            //return true;
        }
            // hasPathCore(matrix,rows,cols,row-1,col,str,strLength, visited);
        else if(row+1<rows&&(visited[(row+1)*cols+col]==0)&&matrix[(row+1)*cols+col]==str[strLength])
        {
            hasPathCore(matrix,rows,cols,row+1,col,str,strLength,visited);
            //return true;
        }
            //hasPathCore(matrix,rows,cols,row+1,col,str,strLength,visited);
        else if(col-1>=0&&(visited[row*cols+col-1]==0)&&matrix[row*cols+col-1]==str[strLength])
        {
            hasPathCore(matrix,rows,cols,row,col-1,str,strLength,visited);
            //return true;
        }
            //hasPathCore(matrix,rows,cols,row,col-1,str,strLength,visited);
        else if(col+1<cols&&(visited[row*cols+col+1]==0)&&matrix[row*cols+col+1]==str[strLength])
        {
            hasPathCore(matrix,rows,cols,row,col+1,str,strLength,visited);
            //return true;
        }
        else{
            strLength--;
            visited[row*cols+col]=0;
            result=false;
        }
            //hasPathCore(matrix,rows,cols,row,col+1,str,strLength,visited);
        
        cout<<str[strLength+1]<<endl;
        return result;
    }
*/
    /*
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL||str==NULL)
            return false;
        int* visited=new int[rows*cols];   //一个和原矩阵一样大的数组来记录一个元素是否被访问过
        bool result=false;
        memset(visited,0,rows*cols);
        char* str3;
        int strLength=0;   // 用来记录字符串的下标移动
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                //sprintf(str3,"%c%c",matrix[i*cols+j],str[strLength]);
                //cout<<str3<<endl;
                //cout<<matrix[i*cols+j]<<endl;
                if(matrix[i*cols+j]==str[strLength])
                {
                    result=hasPathCore(matrix,rows,cols,i,j,str,strLength,visited);
                }
                    //result=hasPathCore(matrix,rows,cols,i,j,str,strLength,visited);
                if(result)
                {
                    return result;
                }
                    //return result;
            }
        }
        delete[] visited;
        return result;
    }
private:
    bool hasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int strLength, int* visited)
    {
        // 参数说明matrix矩阵 rows矩阵行数 cols矩阵列数 row当前所在行 col当前所在列 str要匹配字符串的头指针 strLength当前是第几个字符
        // visited记录每个位置是否被访问过
        bool result;
        char* str3;
        int strLengthNow=strLength+1;
        visited[row*cols+col]=1;
        if(str[strLengthNow]=='B')
            return true;
        if(row-1>=0&&(visited[(row-1)*cols+col]==0)&&matrix[(row-1)*cols+col]==str[strLengthNow])
        {
            hasPathCore(matrix,rows,cols,row-1,col,str,strLengthNow,visited);
            //return true;
        }
            // hasPathCore(matrix,rows,cols,row-1,col,str,strLength, visited);
        else if(row+1<rows&&(visited[(row+1)*cols+col]==0)&&matrix[(row+1)*cols+col]==str[strLengthNow])
        {
            hasPathCore(matrix,rows,cols,row+1,col,str,strLengthNow,visited);
            //return true;
        }
            //hasPathCore(matrix,rows,cols,row+1,col,str,strLength,visited);
        else if(col-1>=0&&(visited[row*cols+col-1]==0)&&matrix[row*cols+col-1]==str[strLengthNow])
        {
            hasPathCore(matrix,rows,cols,row,col-1,str,strLengthNow,visited);
            //return true;
        }
            //hasPathCore(matrix,rows,cols,row,col-1,str,strLength,visited);
        else if(col+1<cols&&(visited[row*cols+col+1]==0)&&matrix[row*cols+col+1]==str[strLengthNow])
        {
            hasPathCore(matrix,rows,cols,row,col+1,str,strLengthNow,visited);
            //return true;
        }
        else{
            visited[row*cols+col]=0;
            result=false;
        }
            //hasPathCore(matrix,rows,cols,row,col+1,str,strLength,visited);
        //cout<<str[strLength]<<endl;
        return result;
    }
    */
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==nullptr||str==nullptr||rows<1||cols<1)
            return false;
        bool* visited=new bool[rows*cols];   //一个和原矩阵一样大的数组来记录一个元素是否被访问过
        memset(visited,0,rows*cols);
        int strLength=0;   // 用来记录字符串的下标移动
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(hasPathCore(matrix,rows,cols,i,j,str,strLength,visited))
                    return true;
            }
        }
        delete[] visited;
        return false;
    }
private:
    bool hasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int strLength, bool* visited)
    {
        // 参数说明matrix矩阵 rows矩阵行数 cols矩阵列数 row当前所在行 col当前所在列 str要匹配字符串的头指针 strLength当前是第几个字符
        // visited记录每个位置是否被访问过
        bool hasPath=false;
        if(str[strLength]=='\0')
            return true;
        if(row>=0&&row<rows&&col>=0&&col<cols&&matrix[row*cols+col]==str[strLength]&&!visited[row*cols+col])
        {
            strLength++;
            visited[row*cols+col]==true;
        }
        hasPath=(
            hasPathCore(matrix,rows,cols,row+1,col,str,strLength,visited)||
            hasPathCore(matrix,rows,cols,row-1,col,str,strLength,visited)||
            hasPathCore(matrix,rows,cols,row,col+1,str,strLength,visited)||
            hasPathCore(matrix,rows,cols,row,col-1,str,strLength,visited)
        );
        if(!hasPath)
        {
            strLength--;
            visited[row*cols+col]==false;
        }
        return hasPath;
    }
};
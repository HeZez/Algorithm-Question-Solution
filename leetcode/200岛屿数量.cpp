/*
    给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

    示例 1:
    输入:
    11110
    11010
    11000
    00000
    输出: 1
    
    示例 2:
    输入:
    11000
    11000
    00100
    00011
    输出: 3
*/
/*
    新建一个额外的数组来记录原数组中对应的位置是否被访问过
    遍历数组中每一个是'1'的元素，从这个位置开始搜索，访问过的元素不再进行搜索
    每有一个可搜索的'1' 海岛计数加一
*/
class Solution {
public:
    int res=0;
    int numIslands(vector<vector<char>>& grid) {
        // 这个实现的写法能过 但是效率比较低  接下来在search函数那里修改一下
        if(grid.empty()||grid[0].empty())
            return res;
        vector<vector<bool>> flagMap(grid.size(), vector<bool>(grid[0].size(), true));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'&&flagMap[i][j])
                {
                    res++;
                    searchIsland(grid, flagMap, i, j);
                    /*
                    for(int x=0;x<grid.size();x++)
                    {
                        for(int y=0;y<grid[0].size();y++)
                        {
                            cout<<flagMap[x][y]?'1':'0'<<',';
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                    */
                }
            }
        }
        return res;
    }
    /*
    void searchIsland(vector<vector<char>>& grid, vector<vector<bool>>& flagMap, int i, int j)
    {
        flagMap[i][j]=false;
        if(i+1<grid.size()&&grid[i+1][j]=='1'&&flagMap[i+1][j])
            searchIsland(grid, flagMap, i+1, j);
        if(i-1>=0&&grid[i-1][j]=='1'&&flagMap[i-1][j])
            searchIsland(grid, flagMap, i-1, j);
        if(j+1<grid[0].size()&&grid[i][j+1]=='1'&&flagMap[i][j+1])
            searchIsland(grid, flagMap, i, j+1);
        if(j-1>=0&&grid[i][j-1]=='1'&&flagMap[i][j-1])
            searchIsland(grid, flagMap, i, j-1);
    }
    */
    // 修改后的search
    void searchIsland(vector<vector<char>>& grid, vector<vector<bool>>& flagMap, int i, int j)
    {
        if( i<0||i>=grid.size() || j<0||j>=grid[0].size() || grid[i][j]=='0')
            return ;
        if(flagMap[i][j]==false)
            return ;
        flagMap[i][j]=false;
        searchIsland(grid, flagMap, i+1, j);
        searchIsland(grid, flagMap, i-1, j);
        searchIsland(grid, flagMap, i, j+1);
        searchIsland(grid, flagMap, i, j-1);
    }
};
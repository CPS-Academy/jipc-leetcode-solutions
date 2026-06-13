class Solution {
public:
void check(vector<vector<int>>& board,int row,int col)
{
    int count=0;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(i==0 && j==0) continue;
            int r=row+i;
            int c=col+j;
            if(r>=0&&c>=0&&r<board.size()&&c<board[0].size())
            {
                if(board[r][c]==1 || board[r][c] == 4)
                {
                    count++;
                }
            }
        }
    }
    if(board[row][col]==1&&count<2)
    {
        board[row][col]=4;
    }
    else if(board[row][col]==1&&count>3)
    {
        board[row][col]=4;
    }
    else if(board[row][col]==0&&count==3)
    {
        board[row][col]=3;
    }
}

    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                check(board,i,j);
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == 3) board[i][j] = 1;
                if(board[i][j] == 4) board[i][j] = 0;
            }
        }   
    }
};

/*
    3 -> (0 -> 1)
    4 -> (1 -> 0)
*/
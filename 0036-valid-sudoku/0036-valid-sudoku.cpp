class Solution {
public: 
    bool check1(vector<vector<char>>& board,int ii,int jj)
    {
          int startrow = (ii/3)*3;
          int startcol = (jj/3)*3;
          int endrow = (ii/3)*3+2;
          int endcol = (jj/3)*3+2;
          int target = board[ii][jj];
          for(int i=startrow;i<=endrow;i++)
          {
            for(int j=startcol;j<=endcol;j++)
            {
                if(i==ii && j==jj)continue;
                if(board[i][j]==target)return false;
            }
          }
          return true;
    }
    bool check2(vector<vector<char>>& board,int ii,int j)
    {
        int target = board[ii][j];
        for(int i=0;i<9;i++)
        {
            if(i==ii)continue;
            if(board[i][j]==target)return false;
        }
        return true;
    }
    bool check3(vector<vector<char>>& board,int i,int jj)
    {
        int target = board[i][jj];
        for(int j=0;j<9;j++)
        {
            if(j==jj)continue;
            if(board[i][j]==target)return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]>='0' && board[i][j]<='9')
                {
                    bool isvalid = (check1(board,i,j) && check2(board,i,j) && check3(board,i,j));
                    if(!isvalid)return false;
                }
            }
        }
        return true;
    }
};
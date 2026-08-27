
bool check(int i,int j,int n,int m)
        {
            if(i<0 || j<0)return false;
            if(i>=n || j>=m)return false;
            return true;
        }
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int n=board.size();
        int m = board[0].size();

        

        for(int i=0;i<n;i++)
        {
            int z=0;
            for(int j=0;j<m;j++)
            {
                z=0;
                //diagonal;
                if(check(i-1,j-1,n,m))z+=board[i-1][j-1] & 1;
                if(check(i-1,j+1,n,m))z+=board[i-1][j+1] & 1;
                if(check(i+1,j+1,n,m))z+=board[i+1][j+1] & 1;
                if(check(i+1,j-1,n,m))z+=board[i+1][j-1] & 1;
                //->-<-
                if(check(i,j+1,n,m))z+=board[i][j+1] & 1;
                if(check(i,j-1,n,m))z+=board[i][j-1] & 1;
                if(check(i+1,j,n,m))z+=board[i+1][j] & 1;
                if(check(i-1,j,n,m))z+=board[i-1][j] & 1;

                int cur = board[i][j] & 1;
                if(cur==1 && (z==2 || z==3)) board[i][j] |= 2;   // stays alive
                if(cur==0 && z==3)           board[i][j] |= 2;   // becomes alive
                // otherwise bit 1 stays 0 (dead)
                // if(z<2)board[i][j]=0;
                // if(z>3)board[i][j]=0;
                // if(z==3)board[i][j]=1;
                // z=0;
                
            }

        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                board[i][j] >>= 1;
        
    }
};
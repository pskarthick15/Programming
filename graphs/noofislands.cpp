void dfs(vector<vector<char>>arr,int i,int j,vector<vector<bool>>&vis,int n,int m)
    {
        vis[i][j]=1;
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && arr[ni][nj]=='1')
            {
                dfs(arr,ni,nj,vis,n,m);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(grid,i,j,vis,n,m);
                    cnt++;
                }

            }
        }
        return cnt;
    }

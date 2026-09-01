class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size();
        int m=classroom[0].size();
        int sr=-1;
        int sc=-1;
        int cnt=0;
        vector<vector<int>> id(n, vector<int>(m, -1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(classroom[i][j]=='S')
                {
                    sr=i;
                    sc=j;
                }
                if(classroom[i][j]=='L') id[i][j]=cnt++;
            }
        }
        int masks=1<<cnt;
        int fullMask=masks-1;
        
        vector<vector<vector<int>>> best(n, vector<vector<int>>(m, vector<int>(masks, -1)));
        
        struct State
        {
            int r;
            int c;
            int mask;
            int en;
            int dist;
        };
        
        queue<State> q;
        q.push({sr, sc, 0, energy, 0});
        best[sr][sc][0]=energy;
        
        int dr[]={-1, 1, 0, 0};
        int dc[]={0, 0, -1, 1};
        
        while(!q.empty())
        {
            State cur=q.front();
            q.pop();
            
            int r=cur.r;
            int c=cur.c;
            int mask=cur.mask;
            int en=cur.en;
            int dist=cur.dist;
        
            if(mask==fullMask) return dist;
            if(en==0) continue;
            
            for(int d=0;d<4;d++)
            {
                int nr=r+dr[d];
                int nc=c+dc[d];
                
                if(nr<0 || nr>=n || nc<0 || nc>=m || classroom[nr][nc]=='X') continue;
                
                int newEn=en-1;
                int newMask=mask;
                
                if(classroom[nr][nc]=='L')
                {
                    newMask|=(1<<id[nr][nc]);
                }
                
                if(classroom[nr][nc]=='R') newEn=energy;
                
                if(best[nr][nc][newMask]>=newEn) continue;
                
                best[nr][nc][newMask]=newEn;
                q.push({nr, nc, newMask, newEn, dist+1});
            }
        }
        
        return -1;
    }
};
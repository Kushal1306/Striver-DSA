#include<bits/stdc++.h>
using namespace std;
int R,C;
int kkj[501][501];
int x8[]={-1,-1,0,1,1,1,0,-1};
int y8[]={0,1,1,1,0,-1,-1,-1};
void bfs(int i,int j)
{
            queue <pair<int,int>> q;
            q.push({i,j});
            kkj[i][j]=0;
            while(!q.empty())
            {
                auto p=q.front();
                q.pop();
                for(int d=0;d<8;d++)
                {
                    int ni=p.first+x8[d];
                    int nj=p.second+y8[d];
                    if(ni>=0&&ni<R&&nj>=0&&nj<C&&kkj[ni][nj]==1)
                    {
                        q.push({ni,nj});
                        kkj[ni][nj]=0;
                    }
                }
            }
}
int main(){
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>R>>C;
        char ch;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                cin>>ch;
                kkj[i][j]=ch-'0';
            }
        }
 
            int cnt=0;
            for(int i=0;i<R;i++)
            {
                for(int j=0;j<C;j++)
                {
                    if(kkj[i][j]==1)
                    {
                        bfs(i,j);
                        cnt++;
                    }
                }
            }
        cout<<cnt<<"\n";
 
    }
    return 0;
}
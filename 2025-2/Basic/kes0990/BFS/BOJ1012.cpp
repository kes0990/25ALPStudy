#include <iostream>
#include <queue>
using namespace std;

int cnt=0;
int farm[50][50];
int vis[50][50];
int M, N,K;
int T;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int sx, int sy, int n, int m){
    queue< pair<int,int> > Q;
    Q.push(make_pair(sx,sy));
    vis[sx][sy]=1;
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int d=0; d<4; d++){
            int nx=dx[d]+cur.first;
            int ny=dy[d]+cur.second;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vis[nx][ny]==1||farm[nx][ny]==0) continue;
            vis[nx][ny]=1;
            Q.push(make_pair(nx,ny));
        }

    }
}


int main(void){
    cin>>T;
    while(T-->0){
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
            vis[i][j]=0;
            farm[i][j]=0;
            }
         }
        cnt=0;
        cin>>M>>N>>K;
        for(int i=0; i<K; i++){
            int x, y;
            cin>>y>>x;
            farm[x][y]=1;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(vis[i][j]==0&&farm[i][j]==1){
                    cnt++;
                    BFS(i, j, N, M);
                }
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}

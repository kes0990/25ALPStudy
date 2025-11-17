#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[300][300];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt = 0;

void BFS(int sx, int sy, bool vis[300][300]){
    queue< pair<int, int> > Q;
    Q.push(make_pair(sx, sy));
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int d=0; d<4; d++){
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(map[nx][ny]==0||vis[nx][ny]==true) continue;
            vis[nx][ny] = true;
            Q.push(make_pair(nx,ny));
        }

    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }

    int result=0;
    while(true){
        bool vis[300][300] = {false};
        int bcnt=0;
        for(int i=1; i<N-1; i++){
            for(int j=1; j<M-1; j++){
                if(map[i][j]>0&&!vis[i][j]){
                    BFS(i,j,vis);
                    bcnt++;
                }
            }
        }
        if(bcnt>=2){
            cout<<result<<"\n"; break;
        }
        if (bcnt==0){
            cout<<0<<"\n";
            break;
        }

        int melt[300][300] = {0};
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                for(int d=0; d<4; d++){
                    if(map[i+dx[d]][j+dy[d]]==0){
                        melt[i][j]++;
                    }
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                map[i][j] -= melt[i][j];
                if(map[i][j]<0){map[i][j]=0;}
            }
        }
        result++;
    }

    return 0;
}

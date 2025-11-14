#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int map[1000][1000];
int dist[2][1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

int main(void){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        string line;
        cin>>line;
        for(int j=0; j<M; j++){
            map[i][j]=line[j]-'0';
        }
    }
    //dist초기화(-1)
    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                dist[i][j][k]=-1;
            }
        }
    }
    queue< tuple<int,int,int> > Q;
    Q.push(make_tuple(0,0,0));
    dist[0][0][0]=1;

    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front();
        Q.pop();
        int state = get<0>(cur);
        int x = get<1>(cur);
        int y = get<2>(cur);
        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y+ dy[d];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(map[nx][ny]==0){
                if(dist[state][nx][ny]==-1){
                    dist[state][nx][ny]=dist[state][x][y]+1;
                    Q.push(make_tuple(state,nx,ny));
                }
            }
            if(map[nx][ny]==1){
                if(state==0&&dist[1][nx][ny]==-1){
                    dist[1][nx][ny]=dist[0][x][y]+1;
                    Q.push(make_tuple(1,nx,ny));
                }
            }
            
        }
    }
    int d1 = dist[0][N-1][M-1];
    int d2 = dist[1][N-1][M-1];
    if(d1==-1&&d2==-1) cout<<-1<<"\n";
    else if(d2==-1)cout<<d1<<"\n";
    else if(d1==-1)cout<<d2<<"\n";
    else{
        if(d1<d2)cout<<d1<<"\n";
        else cout<<d2<<"\n";
    }

    return 0;
}

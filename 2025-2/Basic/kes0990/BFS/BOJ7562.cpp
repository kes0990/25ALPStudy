#include <iostream>
#include <queue>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    int board[300][300];
    int m, n;
    for(int i=0; i<T; i++){
        int I;
        cin>>I;
        
        for(int i=0; i<300; i++){
            for(int j=0; j<300; j++){
                board[i][j]=-1;
            }
        }

        int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

        queue< pair<int,int> >Q;
        int sx, sy;
        cin>>sx>>sy;
        Q.push(make_pair(sx,sy));
        board[sx][sy]=0;

        cin>>m>>n;

        while(!Q.empty()){
            pair<int,int> cur = Q.front();
            Q.pop();
            for(int d=0; d<8; d++){
                int nx = cur.first+dx[d];
                int ny = cur.second+dy[d];
                if(nx<0||nx>=I||ny<0||ny>=I) continue;
                if(board[nx][ny]>=0) continue;
                board[nx][ny]=board[cur.first][cur.second]+1;
                Q.push(make_pair(nx,ny));
            }
        }
        cout<<board[m][n]<<"\n";
    }

    return 0;
}

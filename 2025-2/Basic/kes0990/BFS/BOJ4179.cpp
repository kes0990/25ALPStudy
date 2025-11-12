#include <iostream>
#include <queue>
using namespace std;

char map[1000][1000];
int disF[1000][1000];
int disJ[1000][1000];

queue< pair<int,int> > FQ;
queue< pair<int, int> > JQ;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            disF[i][j]=-1;
            disJ[i][j]=-1;
            if(map[i][j]=='J') {disJ[i][j]=0; JQ.push(make_pair(i,j));}
            if(map[i][j]=='F') {disF[i][j]=0; FQ.push(make_pair(i,j));}

        }
    }


    while(!FQ.empty()){
        pair<int,int> cur = FQ.front();
        FQ.pop();
        for(int d=0; d<4; d++){
            int nx = dx[d]+cur.first;
            int ny = dy[d]+cur.second;
            if(nx<0||nx>=n||ny<0||ny>=m){continue;}
            if(disF[nx][ny]>=0||map[nx][ny]=='#'){continue;}
            disF[nx][ny]=disF[cur.first][cur.second]+1;
            FQ.push(make_pair(nx,ny));
        }
    }

  
    while(!JQ.empty()){
        pair<int,int> cur1 = JQ.front();
        JQ.pop();
        for(int d=0; d<4; d++){
            int nx = dx[d]+cur1.first;
            int ny = dy[d]+cur1.second;
            if(nx<0||nx>=n||ny<0||ny>=m){
                cout<<disJ[cur1.first][cur1.second]+1; return 0;
            }
            if(disJ[nx][ny]>=0||map[nx][ny]=='#'||map[nx][ny]=='J'){continue;}
            if(disF[nx][ny]!=-1&&disF[nx][ny]<=disJ[cur1.first][cur1.second]+1){continue;}
            disJ[nx][ny]=disJ[cur1.first][cur1.second]+1;
            JQ.push(make_pair(nx,ny));
        }
    }
    cout<<"IMPOSSIBLE";



    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

char RGBtable[100][100];
int cntRGB=0, cntRB=0;
int n;
int distRGB[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(char c, int sx, int sy){
    queue< pair<int,int> > Q;
    Q.push(make_pair(sx, sy));
    distRGB[sx][sy]=0;
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int d=0; d<4; d++){
            int nx = dx[d]+cur.first;
            int ny = dy[d]+cur.second;
            if(nx<0||nx>=n||ny<0||ny>=n){continue;}
            if(RGBtable[nx][ny]!=c||distRGB[nx][ny]==0){continue;}
            distRGB[nx][ny] = 0;
            Q.push(make_pair(nx, ny));
        }
    }
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        string line;
        cin>>line;
        for(int j=0; j<n; j++){
            RGBtable[i][j] = line[j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            distRGB[i][j]=-1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(distRGB[i][j]==-1){
                BFS(RGBtable[i][j],i,j);
                cntRGB++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(RGBtable[i][j]=='G'){RGBtable[i][j]='R';}
            distRGB[i][j]=-1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(distRGB[i][j]==-1){
                BFS(RGBtable[i][j],i,j);
                cntRB++;
            }
        }
    }
    cout<<cntRGB<<" "<<cntRB<<"\n";
    
    
    return 0;
}

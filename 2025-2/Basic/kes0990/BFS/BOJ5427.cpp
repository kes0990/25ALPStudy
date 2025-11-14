#include <iostream>
#include <queue>
using namespace std;

char map[1000][1000];
int disF[1000][1000];
int disJ[1000][1000];


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int T;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin>>T;
    
    for(int i=0; i<T; i++){
        queue< pair<int,int> > FQ;
        queue< pair<int, int> > JQ; 
        bool suc=false;
        cin>>m>>n;
        for(int i=0; i<n; i++){
            string line;
            cin>>line;
            for(int j=0; j<m; j++){
                map[i][j]=line[j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                disF[i][j]=-1;
                disJ[i][j]=-1;
                if(map[i][j]=='@') {disJ[i][j]=0; JQ.push(make_pair(i,j));}
                if(map[i][j]=='*') {disF[i][j]=0; FQ.push(make_pair(i,j));}

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
                    cout<<disJ[cur1.first][cur1.second]+1<<"\n"; suc =true; break;
                }
                if(disJ[nx][ny]>=0||map[nx][ny]=='#'||map[nx][ny]=='@'){continue;}
                if(disF[nx][ny]!=-1&&disF[nx][ny]<=disJ[cur1.first][cur1.second]+1){continue;}
                disJ[nx][ny]=disJ[cur1.first][cur1.second]+1;
                JQ.push(make_pair(nx,ny));
            }
            if (suc){break;}
        }
        if(suc==true){continue;}
        else cout<<"IMPOSSIBLE\n";
    }    
    return 0;
}

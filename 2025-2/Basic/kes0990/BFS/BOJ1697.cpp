#include <iostream>
#include <queue>
using namespace std;

int dist[100002];
int N, K;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill(dist, dist+100001,-1);
    cin>>N>>K;
    dist[N]=0;
    queue<int> Q;
    Q.push(N);
    while(dist[K]==-1){
        int cur = Q.front();
        Q.pop();
        for(int i=0; i<3; i++){
            int n;
            if(i==0){
                n = cur+1;
            }
            else if(i==1){
                n = cur-1;
            }
            else{
                n = cur*2;
            }

            if(n<0 || n > 100000) continue;
            if(dist[n]!=-1) continue;

            dist[n]=dist[cur]+1;
            Q.push(n);
        }
    }
    cout<<dist[K];

    return 0;
}

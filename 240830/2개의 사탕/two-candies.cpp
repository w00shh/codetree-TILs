#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N,M;
char arr[15][15];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int fr,fb;

void input(){
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j] == 'R'){
                fr = i* M + j;
                arr[i][j] = '.';
            }
            else if(arr[i][j] == 'B'){
                fb = i* M + j;
                arr[i][j] = '.';
            }
        }
    }
}

int solve(){
    queue<tuple<int,int,int>> que; // red, blue, cnt
    que.push({fr,fb,0});
    int rx,ry,bx,by,c,r,b;
    int rnx,rny,bnx,bny;
    while(!que.empty()){
        tie(r,b,c) = que.front();
        que.pop();

        if(c>=10) continue;

        rx = r/M, ry = r%M;
        bx = b/M, by = b%M;

        for(int i=0;i<4;i++){
            rnx = rx, rny = ry, bnx = bx, bny = by;
            while(true){
                rnx += dx[i];
                rny += dy[i];
                
                if(rnx < 0 || rny < 0 || rnx >= N || rny >= M) continue;
                if(arr[rnx][rny] == '#'){
                    rnx -= dx[i];
                    rny -= dy[i];
                    break;
                }
                
                if(arr[rnx][rny] == 'O'){
                    break;
                }
            }
            while(true){
                bnx += dx[i];
                bny += dy[i];
                
                if(bnx < 0 || bny < 0 || bnx >= N || bny >= M) continue;
                if(arr[bnx][bny] == '#'){
                    bnx -= dx[i];
                    bny -= dy[i];
                    break;
                }
                if(arr[bnx][bny] == 'O'){
                    break;
                }
            }

            if(arr[bnx][bny] == 'O') continue;
            if(arr[rnx][rny] == 'O') return c + 1;

            if(rnx == bnx && rny == bny) {
                if(abs(rnx - rx) + abs(rny - ry) > abs(bnx - bx) + abs(bny - by)) {
                    rnx -= dx[i];
                    rny -= dy[i];
                } else {
                    bnx -= dx[i];
                    bny -= dy[i];
                }
            }

            que.push({rnx*M+rny,bnx*M+bny,c+1});
        }
    }
    return -1;
}

int main() {
    input();
    cout << solve();    


    return 0;
}
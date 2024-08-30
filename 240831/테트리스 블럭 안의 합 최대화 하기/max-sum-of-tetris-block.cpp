#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[205][205];
int visited[205][205];
int result = -1;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void input(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
}

void solve(int x,int y,int cnt,int val){
    if(cnt == 4){
        result = max(val,result);
        return;
    }
    
    int nx,ny;
    for(int i=0;i<4;i++){
        nx = x+dx[i]; ny = y+dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        solve(nx,ny,cnt+1,val+arr[nx][ny]);
        if(cnt == 2){
            solve(x,y,cnt+1,val+arr[nx][ny]);
        }
        visited[nx][ny] = 0;
    }   
}

int main() {
    input();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 1;
            solve(i,j,1,arr[i][j]);
            visited[i][j] = 0;
        }
    }

    cout << result << "\n";

    return 0;
}
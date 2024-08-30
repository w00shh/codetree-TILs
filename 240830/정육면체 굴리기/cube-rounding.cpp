#include <iostream>
using namespace std;

int n,m,x,y,k;
int arr[25][25];
int roll_dir[1005];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dice[6] = {0,0,0,0,0,0};

void input(){
    cin >> n >> m >> x >> y >> k;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<k;i++){
        cin >> roll_dir[i];
    }
}

int change_arr[4][6] = {{1,5,0,3,4,2},{2,0,5,3,4,1},{3,1,2,5,0,4},{4,1,2,0,5,3}};

void change_dice(int dir){
    int new_dice[6];
    for(int i=0;i<6;i++){
        new_dice[i] = dice[change_arr[dir][i]];
    }
    for(int i=0;i<6;i++){
        dice[i] = new_dice[i];
    }
}

void roll_dice(int dir){
    // 벗어나는 경우
    if(x+dx[dir] < 0 || y+dy[dir] < 0 || x+dx[dir] >= n || y+dy[dir] >= m){
        return;
    }

    // 주사위 형태 바꾸기
    change_dice(dir);
    
    // 주사위 위치 변경
    x += dx[dir]; y += dy[dir];

    if(arr[x][y] == 0){
        arr[x][y] = dice[0];
    }
    else{
        dice[0] = arr[x][y];
        arr[x][y] = 0;
    }

    cout << dice[5] << "\n";

    return;
}

int main() {
    input();
    for(int i=0;i<k;i++){
        roll_dice(roll_dir[i]-1);
    }
    return 0;
}
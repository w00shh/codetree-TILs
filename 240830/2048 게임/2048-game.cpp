#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[25][25];
int tmp_arr[25][25];
int dir[5];
int result = -1;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            tmp_arr[i][j] = arr[i][j];
        }
    }
}

void rotate(int rot_dir){
    int rot_arr[25][25];


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rot_arr[i][j] = arr[i][j];
        }
    }

    if(rot_dir == 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = rot_arr[n-j-1][i];
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = rot_arr[j][n-i-1];
            }
        }
    }
}

void solve(int d){
    int cur_arr[25][25];
    for(int i=0;i<n;i++){
        memset(cur_arr[i],0,sizeof(int)*n);
    }

    int chk = -1;

    if(d == 2){
        rotate(0);
    }
    else if(d == 3){
        rotate(1);
    }
    // 좌측으로 수행
    if(d == 0 || d == 2){
        for(int i=0;i<n;i++){
            int push_idx = 0;
            chk = -1;
            for(int j=0;j<n;j++){
                if(arr[i][j] != 0){
                    if(chk == -1){
                        chk = arr[i][j];                        
                    }
                    else if(chk != arr[i][j] && chk != -1){
                        cur_arr[i][push_idx] = chk;
                        push_idx++;
                        chk = arr[i][j];
                    }
                    else{
                        cur_arr[i][push_idx] = chk * 2;
                        push_idx++;
                        chk = -1;
                    }
                }
            }
            if(chk != -1){
                cur_arr[i][push_idx] = chk;
            }
        }
    }
    // 우측으로 수행
    if(d == 1 || d == 3){
        for(int i=n-1;i>=0;i--){
            int push_idx = n-1;
            chk = -1;
            for(int j=n-1;j>=0;j--){
                if(arr[i][j] != 0){
                    if(chk == -1){
                        chk = arr[i][j];
                    }
                    else if(chk != arr[i][j] && chk != -1){
                        cur_arr[i][push_idx] = chk;
                        push_idx--;
                        chk = arr[i][j];
                    }
                    else{
                        cur_arr[i][push_idx] = chk * 2;
                        push_idx--;
                        chk = -1;
                    }
                }
            }
            if(chk != -1){
                cur_arr[i][push_idx] = chk;
            }
        }
    }
    // 하로 수행
    if(d == 2){
        rotate(1);
    }
    else if(d == 3){
        rotate(0);
    }

    // 결과를 arr에 저장
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = cur_arr[i][j];
        }
    }
    return;
}

void permu(int cnt){
    if(cnt == 5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = tmp_arr[i][j];
            }
        }

        for(int i=0;i<5;i++){
            solve(dir[i]);
        }

        // 결과 비교
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] > result) result = arr[i][j];
            }
        }
        return;
    }

    for(int i=0;i<4;i++){
        dir[cnt] = i;
        permu(cnt+1);
    }
}

int main() {
    input();
    permu(0);
    cout << result << "\n";
    return 0;
}
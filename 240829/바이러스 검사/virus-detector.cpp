#include <iostream>
using namespace std;

long long N; // 식당
long long customer[1000001]; // 각 식당 고객
long long can_search[2]; // 각 식당 팀장,팀원 최대 검색 고객 수

void input(){
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> customer[i];
    }

    cin >> can_search[0] >> can_search[1];
}

int solve(){
    int result = 0;
    for(int i=0;i<N;i++){
        customer[i] -= can_search[0];
        result += 1;
        if(customer[i] <= 0){
            continue;
        }
        if(customer[i] % can_search[1] == 0){
            result += customer[i] / can_search[1];
        }
        else{
            result += customer[i] / can_search[1] + 1;
        }
    }
    return result;
}

int main() {
    input();
    int result = solve();
    cout << result << "\n";
    return 0;
}
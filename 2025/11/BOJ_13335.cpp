// BOJ 13335 - 트럭

#include<iostream>
#include<queue>

using namespace std;

int solve(int w, int L, queue<int> truck){
    queue<int> bridge;

    int total_weight = 0;
    int timer = 0;
    for(int i = 0; i < w; i++){
        bridge.push(0);
    }

    while(!truck.empty()){
        total_weight -= bridge.front();
        if(total_weight + truck.front() <= L){
            bridge.push(truck.front());
            total_weight+= truck.front();
            truck.pop();
        }
        else{
            bridge.push(0);
        }
        bridge.pop();
        timer++;
    }

    return timer + w;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w, L;
    cin >> n >> w >> L;

    queue<int> truck;
    for(int i = 0; i<n; i++){
        int t_weigth;
        cin >> t_weigth;
        truck.push(t_weigth);
    }

    cout << solve(w, L, truck);

    return 0;
    
}
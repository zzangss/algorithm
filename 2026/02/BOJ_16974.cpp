// boj 16974 레벨 햄버거 

#include<iostream>
#include<math.h>

using namespace std;

long long layer[51], patty[51];

// 레벨-N 햄버거의 레이어 개수와 패티 개수 계산해두기.
void preCompute(int n){
    layer[0] = 1;
    patty[0] = 1;
    for(int i = 1; i <= n; i++){
	   layer[i] = layer[i-1] * 2 + 3;
       patty[i] = patty[i-1] * 2 + 1;
    }
}

// 레벨-N 햄버거의 아래서부터 X장에 포함된 패티의 개수
long long solve(int n, long long x){
    /*
    cout << "bugger " << n << endl;
    cout << "x : " << x << endl;
    cout << "layer num : " << layer[n] << endl;
    cout << "patty num : " << patty[n] << endl;
    */
    
    if(x <= 0){
        return 0;
    }
    if(x == layer[n]){
        return patty[n];
    }
    if(x <= layer[n] / 2){
        return solve(n-1, x-1);
    }
    else{
        return patty[n] - solve(n - 1, layer[n] - x - 1);
    }
}

int main(){
    int n;
    long long x;
    cin >> n >> x;

    preCompute(50);
    cout << solve(n, x);

    return 0;
}
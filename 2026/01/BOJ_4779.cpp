// boj 4779 칸토어 집합

#include<iostream>
#include<string>
#include<math.h>

using namespace std;

string calCantor(int k){
    if(k <= 0){
        return "-";
    }

    string emp = "";
    for(int i = 0; i < pow(3, k - 1); i++){
        emp += " ";
    }
    string prev_cantor = calCantor(k - 1);
    return prev_cantor + emp + prev_cantor;
}

int main(){
    int n;
    while(cin >> n){
        cout << calCantor(n) << "\n";
    }

    return 0;
}
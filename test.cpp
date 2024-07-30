#include <iostream>
#include<unordered_map>

using namespace std;


int main() {
    int n, k; cin >> n >> k;

    unordered_map<int, int> um;
    int check

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (um.find(num) == um.end()) {
            um[num] = 1;
        }
        else {
            um[num]++;
        }
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        if(i == k-i)
    }

}
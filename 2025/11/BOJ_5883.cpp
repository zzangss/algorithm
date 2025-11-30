// BOJ 5883 - 아이폰 9s

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    set<int> s;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    
    int result = 0;
    for(int target : s){
        int c_len = 0;
        int c_max = 0;
        int prev = -1;
        
        for(int i = 0; i<n; i++){
            if(arr[i] == target) continue;
            
            if(arr[i] == prev){
                c_len++;
            }
            else{
                c_len = 1;
                prev = arr[i];
            }
            
            c_max = max(c_max, c_len);
        }
        
        result = max(result, c_max);
    }
    
    cout << result;
    
    return 0;
}
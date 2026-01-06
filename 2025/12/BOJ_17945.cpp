#include<iostream>
#include<math.h>
// BOJ 17945 - 통학의 신신


using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int result1 = -a - sqrt(a*a - b);
    int result2 = -a + sqrt(a*a - b);
    
    if(result1 == result2){
        cout << result1;
        return 0;
    }
    cout << result1 << " " << result2;

    return 0;
}
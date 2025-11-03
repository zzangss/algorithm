// BOJ 4673 - ¼¿ÇÁ ³Ñ¹ö

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i < 10000; i++) {
        bool isSelf = true;
        for (int j = 1; j <= i; j++) {
            int sum = 0, temp = j;
            sum += temp;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum == i) {
                isSelf = false;
            }
        }
        if (isSelf) {
            cout << i << "\n";
        }
    }

    return 0;
}
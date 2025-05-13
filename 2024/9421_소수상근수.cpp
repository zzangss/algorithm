#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#define NUM_OF_PRIME 1000000

using namespace std;

vector<bool> prime_num(NUM_OF_PRIME + 1, true);

void findPrime() {
    for (int i = 2; i <= sqrt(NUM_OF_PRIME); i++)
    {
        for (int k = i * i; k <= NUM_OF_PRIME; k += i)
        {
            if (!prime_num[k])
            {
                continue;
            }
            prime_num[k] = false;
        }
    }
}

int sumOfDigits(const int n) {
    int temp = n;
    int sum = 0;
    while (temp) {
        sum += pow(temp % 10, 2);
        temp /= 10;
    }
    return sum;
}

bool isSangGeun(const int n) {
    map<int, bool> check;
    int sum = sumOfDigits(n);

    while (true) {
        sum = sumOfDigits(sum);
        if (sum == 1) {
            return true;
        }
        else if(check[sum]) {
            return false;
        }
        check[sum] = true;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    findPrime();

    int n; cin >> n;

    for (int i = 2; i <= n; i++) {
        if (prime_num[i] && isSangGeun(i)) cout << i << " ";
    }

}
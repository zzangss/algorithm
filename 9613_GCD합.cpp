#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return b;

    if (a % b == 0) { return b; }
    else { return gcd(b, a % b); }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<long long> v(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum += gcd(v[j], v[k]);
            }
        }
        cout << sum << "\n";
    }
}
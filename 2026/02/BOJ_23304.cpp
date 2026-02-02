// boj 23304 아카라카

#include<iostream>
#include<string>

using namespace std;

bool isPal(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool solve(string s) {
    // 기저조건. 
    if (s.size() <= 1) {
        return true;
    }
    if(!isPal(s)) {
        return false;
	}
    
    s = s.substr(0, s.size() / 2);
    
    return solve(s);
}

int main() {
    string s;
    cin >> s;

    if (solve(s)) {
        cout << "AKARAKA";
    }
    else {
        cout << "IPSELENTI";
    }

    return 0;
}
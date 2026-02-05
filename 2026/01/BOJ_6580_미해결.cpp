// boj 6580 쿼드 트리

#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

// 16 -> 10 진수 변환 
int hexToDec(string s){
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        result *= 16;
        if(s[i] <= '9' && s[i] >='0'){
            result += (s[i] - '0');
        }
        else if(s[i] <= 'f' && s[i] >= 'a'){
            result += (s[i] - 'a' + 10);
        }
    }
    return result;
}

// 10 -> 2 진수 변환 
string decToBin(int n, int s){
    string result = "";
    for(int i = 0; i<n; i++){
        result += to_string(s % 2);
        s /= 2;
    }
    return result;
}

// 필요없는 입력값 무시해주는 함수. 
void throwString(int n){
    string trash_s;
    for(int i = 0; i < n; i++){
        cin >> trash_s;
    }
}

// 문제에서 요구하는 중요 정보만 파싱하는 함수
string parsing(int n, string s){
    string result = "";
    string temp = "";
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ',' && i - 2 >= 0){
            //cout << endl << "before parsing" << s[i - 1] << s[i-2] << endl;
            temp += s[i-2];
            temp += s[i-1];
            //cout << "temp : " << temp << endl;
            result = decToBin(n, hexToDec(temp));
        }
    }
    //cout << "after parsing : " << result << endl;
    return result;
}

// string s의 모든 char값이 같은지 확인하는 함수
bool checkIsSame(string s){
    char temp = s[0];
    for(int i = 1; i<s.size(); i++){
        if(temp != s[i]){
            return false;
        }
    }
    return true;
}

int cnt = 0;
string solve(int n, int row, int col, const vector<string>& xbm){
    string result = "";
    string temp = "";
    
    // 섞여있는지 확인하기 위해 string으로 붙여줌. 
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            temp += xbm[row + i][col + k];
        }
    }

    // 만약 안 섞여있으면
    if(checkIsSame(temp)){
        if(temp[0] == '1'){
            return "B";
        }
        else{
            return "W";
        }
    }
    // 만약 섞여있으면 -> 4등분 해줘야함.
    else{
        result += solve(n/2, row, col, xbm) 
                + solve(n/2, row, col + n/2, xbm) 
                + solve(n/2, row + n/2, col, xbm) 
                + solve(n/2, row + n/2, col + n/2, xbm);
        return 'Q' + result;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char trash_c;
    int n;

    throwString(2);
    cin >> n;
    throwString(2);
    cin >> n;

    throwString(3);
    cin >> trash_c >> trash_c;

    vector<string> xbm(n, "");
    string str;
    for(int i = 0; i<n; i++){
        cin >> str;
        xbm[i] = parsing(n, str);
    }
    throwString(1);
    
    /*
    for(int i = 0; i<n; i++){
        cout << xbm[i] << endl;
    }
    */
    
    cout << n << "\n";
    cout << solve(n, 0, 0, xbm);

    return 0;
}
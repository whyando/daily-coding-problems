#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int N = s.size();

    vector<int> dp(N+1, 0);
    dp[0] = 1;
    for(int k=1;k<=N;k++){
        if(s[k-1] != '0')
            dp[k] += dp[k-1]; 

        if(k >= 2){         
            if((s[k-2] == '1') || (s[k-2] == '2' && s[k-1] <= '6'))
                dp[k] += dp[k-2];
        }
    }
    cout << dp[N] << endl;

    return 0;
}
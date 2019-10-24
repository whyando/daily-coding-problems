#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    vector<int> count(26, 0);
    int distinct = 0;
    int i = 0, j = 0;
    int ans = 0; // longest substring length
    while(j != N){
        if(distinct <= K){ // increase j
            ans = max(ans, j-i);
            j++;
            
            if(count[s[j]-'a'] == 0) distinct++;
            count[s[j]-'a']++;
        }
        else {              // increase i
            count[s[i]-'a']--;
            if(count[s[i]-'a'] == 0) distinct--;

            i++;
        }
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> dict(N);
    for(int i=0;i<N;i++)
        cin >> dict[i];

    sort(dict.begin(), dict.end());
    
    string q = "de";
    auto it1 = lower_bound(dict.begin(), dict.end(), q);

    string q1 = q;
    q1.back()++; // "df"
    auto it2 = lower_bound(dict.begin(), dict.end(), q1);
    
    for(auto i = it1; i != it2; i++){
        cout << *i << endl;
    }

    return 0;
}
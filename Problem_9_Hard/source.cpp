#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    
    int i = 0;
    int dp1 = A[0];
    int dp2 = 0;
    for(i=1;i<N;i++){ 
        int dp1_next = A[i] + dp2;
        int dp2_next = max(dp1, dp2);

        dp1 = dp1_next;
        dp2 = dp2_next;
    }

    cout << max(dp1, dp2) << endl;

    return 0;
}
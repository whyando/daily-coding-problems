#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1); // make A[] 1 unit larger so we can more easily track whether we've seen N
    for(int i=0;i<N;i++)
        cin >> A[i];
    A[N] = 0; 

    // get rid of negatives
    for(int i=0;i<N;i++)
        A[i] = max(0, A[i]);

    
    for(int i=0;i<N;i++){
        int x = abs(A[i]);
        if(x >= 1 && x <= N){
            // ensure negative bit is set on A[x] to indicate hit
            A[x] = -abs(A[x]);
        }
    }
    
    // find first x with negative bit not set, or N+1 if all are set
    int ans = 1;
    while(ans != N+1 && A[ans] < 0) ans++;

    cout << ans << endl;

    return 0;
}
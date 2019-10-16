#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> X(N),Y(N);

    X[0] = 1;
    for(int i=1;i<N;i++)
        X[i] = X[i-1]*A[i-1];

    Y[N-1] = 1;
    for(int i=N-2;i>=0;i--){
        Y[i] = Y[i+1]*A[i+1];
    }

    vector<int> out(N);
    for(int i=0;i<N;i++)
        out[i] = X[i]*Y[i];

    for(int i=0;i<N;i++)
        cout << out[i] << " ";
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    sort(A.begin(), A.end());
    int i = 0;
    int j = N-1;

    while(i != j){
        int sum = A[i] + A[j];
        if(sum < K)
            i++;
        else if(sum > K)
            j--;
        else {
            cout << "True: " << A[i] << " + " << A[j] << " = " << K << endl;
            break;
        }
    }
    if(i == j){
        cout << "False" << endl;
    }

    return 0;
}
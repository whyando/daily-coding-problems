#include <bits/stdc++.h>

using namespace std;

int main(){
    std::mt19937 gen;
    uniform_real_distribution<> dist(-1, 1);

    int trials = 0;
    int successes = 0;
    while(true){
        double x = dist(gen);
        double y = dist(gen);
        if(x*x + y*y <= 1)
            successes++;
        trials++;

        if(trials % 1000000 == 0){
            double estimate = 4.0*successes/trials;
            cout << estimate << endl;
        }
    }

    return 0;
}
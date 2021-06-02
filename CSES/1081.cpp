#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int numberCount;
    cin >> numberCount;

    vector<int> numberReps(1e6 + 1);
    for (int i = 0; i < numberCount; i++) {
        int number;
        cin >> number;
        numberReps[number]++;
    }

    for (int gcd = 1e6; gcd; gcd--) {
        int reps = 0;
        for (int i = gcd; i < numberReps.size(); i += gcd)
            reps += numberReps[i];

        if (reps > 1) {
            cout << gcd;
            break;
        }
    }
}
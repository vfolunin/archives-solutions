#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    vector<int> time(3);
    for (int &time : time)
        if (!(cin >> time))
            return 0;

    vector<int> attempts(3);
    for (int &attempts : attempts)
        cin >> attempts;

    int problemCount = 0, penalty = 0;
    for (int i = 0; i < time.size(); i++) {
        if (time[i]) {
            problemCount++;
            penalty += time[i] + 20 * 60 * (attempts[i] - 1);
        }
    }

    cout << "team " << test << ": " << problemCount << ", " << penalty << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
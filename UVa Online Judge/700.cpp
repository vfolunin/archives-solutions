#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int computerCount;
    cin >> computerCount;

    if (!computerCount)
        return 0;

    vector<int> display(computerCount), start(computerCount), limit(computerCount);
    for (int i = 0; i < computerCount; i++)
        cin >> display[i] >> start[i] >> limit[i];
    
    cout << "Case #" << test << ":\n";
    for (int year = 0; year < 10000; year++) {
        bool ok = 1;
        for (int i = 0; ok && i < computerCount; i++)
            ok &= year >= start[i] && (year - start[i]) % (limit[i] - start[i]) + start[i] == display[i];
        if (ok) {
            cout << "The actual year is " << year << ".\n\n";
            return 1;
        }
    }

    cout << "Unknown bugs detected.\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
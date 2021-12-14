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

    int universityCount;
    cin >> universityCount;

    int teamCount = 0;

    for (int i = 0; i < universityCount; i++) {
        int studentCount;
        cin >> studentCount;
        teamCount += studentCount / 3;
    }

    cout << teamCount * 3 << "\n";
}
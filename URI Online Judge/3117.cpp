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

    int studentCount, minAttendantCount;
    cin >> studentCount >> minAttendantCount;

    int attendantCount = 0;
    for (int i = 0; i < studentCount; i++) {
        int time;
        cin >> time;
        attendantCount += time <= 0;
    }

    cout << (attendantCount >= minAttendantCount ? "YES\n" : "NO\n");
}
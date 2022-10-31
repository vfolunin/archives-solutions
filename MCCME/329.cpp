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

    int studentCount;
    cin >> studentCount;

    for (int i = 0; i < studentCount; i++) {
        string surname, name;
        cin >> surname >> name;

        int minMark = 5;
        for (int j = 0; j < 3; j++) {
            int mark;
            cin >> mark;
            minMark = min(minMark, mark);
        }

        if (minMark > 3)
            cout << surname << " " << name << "\n";
    }
}
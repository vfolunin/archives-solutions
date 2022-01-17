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

    int teamCount;
    cin >> teamCount;

    set<string> universities;

    for (int i = 0; i < teamCount; i++) {
        string university, name;
        cin >> university >> name;

        if (universities.size() < 12 && !universities.count(university)) {
            universities.insert(university);
            cout << university << " " << name << "\n";
        }
    }
}
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

    int roomCount, teamCount;
    cin >> roomCount >> teamCount;

    for (int i = 0; i < teamCount % roomCount; i++)
        cout << string(teamCount / roomCount + 1, '*') << "\n";
    for (int i = teamCount % roomCount; i < roomCount; i++)
        cout << string(teamCount / roomCount, '*') << "\n";
}
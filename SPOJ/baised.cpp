#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int teamCount;
    cin >> teamCount;

    string name;
    vector<int> places(teamCount);
    for (int &place : places)
        cin >> name >> place;

    sort(places.begin(), places.end());

    long long res = 0;
    for (int i = 0; i < places.size(); i++)
        res += abs(i + 1 - places[i]);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
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

    int direction, deltaIndex;
    cin >> direction >> deltaIndex;

    vector<int> delta = { 0, 3, 1, 2 };
    direction = (direction + delta[deltaIndex]) % delta.size();

    cout << direction;
}
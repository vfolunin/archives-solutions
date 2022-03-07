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

    string stones;
    cin >> stones;

    cout << (count(stones.begin(), stones.end(), 'B') * 2 == stones.size());
}
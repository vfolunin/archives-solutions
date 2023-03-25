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

    map<int, int> count;

    string name;
    int score;
    while (cin >> name >> name >> score >> score)
        count[score]++;

    cout << next(count.rbegin())->first << " " << next(count.rbegin())->second;
}
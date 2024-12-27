#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<long long, int> count;
    for (long long value; cin >> value; )
        count[value]++;

    if (count.size() == 2 && count.begin()->second == 1)
        cout << count.begin()->first;
    else if (count.size() == 2 && next(count.begin())->second == 1)
        cout << next(count.begin())->first;
    else
        cout << "NO";
}
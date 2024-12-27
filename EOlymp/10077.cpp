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

    map<long long, int> count;
    for (long long value; cin >> value; )
        count[value]++;

    if (count.size() == 2)
        cout << (count.begin()->second >= count.rbegin()->second ? count.begin()->first : count.rbegin()->first);
    else
        cout << "NO";
}
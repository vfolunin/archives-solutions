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

    set<int> values;
    for (int value; cin >> value && value; )
        values.insert(value);

    cout << *prev(prev(values.end()));
}
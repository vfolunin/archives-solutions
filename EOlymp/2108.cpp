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

    vector<long long> a;
    for (long long value; cin >> value; )
        a.push_back(value);

    reverse(a.begin(), a.end());

    for (long long value : a)
        cout << value << " ";
}
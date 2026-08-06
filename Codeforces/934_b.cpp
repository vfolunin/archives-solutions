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

    long long count;
    cin >> count;

    if (count > 36)
        cout << -1;
    else
        cout << string(count / 2, '8') << string(count % 2, '4');
}
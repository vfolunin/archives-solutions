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

    cout << string(7, ' ') << "A\n";
    for (int out = 6, c = 'B', in = 1; c <= 'E'; out--, c++, in += 2)
        cout << string(out, ' ') << (char)c << string(in, ' ') << (char)c << "\n";
    for (int out = 4, c = 'D', in = 5; c >= 'B'; out++, c--, in -= 2)
        cout << string(out, ' ') << (char)c << string(in, ' ') << (char)c << "\n";
    cout << string(7, ' ') << "A\n";
}
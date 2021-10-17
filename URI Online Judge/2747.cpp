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

    cout << string(39, '-') << "\n";
    for (int i = 0; i < 5; i++)
        cout << "|" << string(37, ' ') << "|\n";
    cout << string(39, '-') << "\n";
}
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

    for (char c = 'a'; c <= 'z'; c++)
        cout << (int)c << " e " << c << "\n";
}
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

    for (int c = 0; c < 256; c++) {
        cout << (char)c;
        if (c % 60 == 59)
            cout << "\n";
    }
}
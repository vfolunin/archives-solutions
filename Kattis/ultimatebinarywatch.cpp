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

    string time;
    cin >> time;

    for (int bit = 3; bit >= 0; bit--) {
        cout << (((time[0] - 0) & (1 << bit)) ? "* " : ". ");
        cout << (((time[1] - 0) & (1 << bit)) ? "*   " : ".   ");
        cout << (((time[2] - 0) & (1 << bit)) ? "* " : ". ");
        cout << (((time[3] - 0) & (1 << bit)) ? "*\n" : ".\n");
    }
}
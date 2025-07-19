#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int percent, size;
    cin >> percent >> size;

    int count = size * percent / 100;

    cout << "[" << string(count, '#') << string(size - count, '-') << "] |" << setw(4) << percent << "%\n";
}
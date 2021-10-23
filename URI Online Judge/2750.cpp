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

    cout << string(39, '-') << "\n";
    cout << "|  decimal  |  octal  |  Hexadecimal  |\n";
    cout << string(39, '-') << "\n";
    for (int i = 0; i < 16; i++) {
        cout << "|";
        cout << setw(7) << dec << i << setw(5) << "|";
        cout << setw(5) << oct << i << setw(5) << "|";
        cout << setw(8) << hex << uppercase << i << setw(9) << "|\n";
    }
    cout << string(39, '-') << "\n";
}
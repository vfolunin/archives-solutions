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

    int start, size;
    cin >> start >> size;
    start--;

    cout << "Sun Mon Tue Wed Thr Fri Sat\n";
    for (int i = 1 - start, x = 0; i <= size; i++, x++) {
        if (i >= 1)
            cout << setw(3) << i;
        else
            cout << "   ";
        cout << (i == size || x % 7 == 6 ? "\n" : " ");
    }
}
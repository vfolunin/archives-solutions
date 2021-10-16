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

    int num, den;
    cin >> num >> den;

    int rem = 0;
    while ((num - rem) % den)
        rem++;

    cout << (num - rem) / den << " " << rem << "\n";
}
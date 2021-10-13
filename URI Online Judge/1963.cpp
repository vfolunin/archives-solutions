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
    
    double before, after;
    cin >> before >> after;

    cout.precision(2);
    cout << fixed << (after - before) / before * 100 << "%\n";
}
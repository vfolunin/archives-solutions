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
    
    double num, den;
    cin >> num >> den;

    cout.precision(2);
    cout << fixed << num / den << "\n";
}
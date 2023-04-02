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

    int n;
    cin >> n;

    vector<string> names = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };

    cout << names[n];
}
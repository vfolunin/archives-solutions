#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <functional>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    string s;
    getline(cin, s);

    vector<int> a;
    int value;

    for (stringstream ss(s); ss >> value; )
        a.push_back(value);

    cin >> value;

    cout << upper_bound(a.begin(), a.end(), value, greater<int>()) - a.begin() + 1;
}
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

    string a, b;
    cin >> a >> b;

    replace(a.begin(), a.end(), '6', '5');
    replace(b.begin(), b.end(), '6', '5');
    
    cout << stoi(a) + stoi(b) << " ";

    replace(a.begin(), a.end(), '5', '6');
    replace(b.begin(), b.end(), '5', '6');

    cout << stoi(a) + stoi(b);
}
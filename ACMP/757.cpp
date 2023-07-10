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
 
    long long c, h, o;
    cin >> c >> h >> o;
 
    cout << min({ c / 2, h / 6, o });
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool has6(int n) {
    string s = to_string(n);
    return s.find('6') != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    do {
        n++;
    } while (has6(n * n));

    cout << n;
}
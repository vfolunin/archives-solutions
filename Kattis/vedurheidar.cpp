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

    int value, size;
    cin >> value >> size;

    for (int i = 0; i < size; i++) {
        string s;
        int limit;
        cin >> s >> limit;
        
        cout << s << (value <= limit ? " opin\n" : " lokud\n");
    }
}
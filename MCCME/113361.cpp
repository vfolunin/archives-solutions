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
 
    int size, opCount;
    string s;
    cin >> size >> opCount >> s;

    string to(26, 'a');
    for (int i = 0; i < to.size(); i++)
        to[i] += i;

    for (int i = 0; i < opCount; i++) {
        char a, b;
        cin >> a >> b;
        swap(to[to.find(a)], to[to.find(b)]);
    }

    for (char c : s)
        cout << to[c - 'a'];
}
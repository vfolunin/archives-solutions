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

    string s;
    getline(cin, s);

    int l = s.find('h'), r = s.rfind('h');
    
    for (int i = 0; i <= l; i++)
        cout << s[i];
    for (int i = l + 1; i < r; i++)
        cout << s[i];
    for (int i = l + 1; i < r; i++)
        cout << s[i];
    for (int i = r; i < s.size(); i++)
        cout << s[i];
}
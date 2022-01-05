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
    cin >> s;

    cout << s;
    if (s.find("13") == -1)
        cout << " NO";
    cout << " es de Mala Suerte\n";
}
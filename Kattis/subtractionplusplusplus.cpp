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
 
    int size;
    cin >> size;

    for (int block = 1; 1; block++) {
        if (size < block) {
            cout << "NO";
            break;
        }
        size -= block;

        if (size < block) {
            cout << "YES";
            break;
        }
        size -= block;
    }
}
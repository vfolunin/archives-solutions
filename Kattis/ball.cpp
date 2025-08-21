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

    vector<int> count(size);
    for (int i = 0; i <= size / 2; i++) {
        int a, b;
        cin >> a >> b;
        
        count[a - 1]++;
        count[b - 1]++;
    }

    for (int i = 0; i < count.size(); i++)
        if (count[i] == 2)
            cout << i + 1 << " ";
}
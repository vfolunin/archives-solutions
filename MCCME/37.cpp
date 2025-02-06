#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int pairCount;
    cin >> pairCount;

    unordered_set<int> prohibited;
    for (int i = 0; i < pairCount; i++) {
        int a, b;
        cin >> a >> b;

        prohibited.insert(a * 10000 + b);
        prohibited.insert(b * 10000 + a);
    }

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j + 1 < a.size(); j++)
            if (a[j] > a[j + 1] && !prohibited.count(a[j] * 10000 + a[j + 1]))
                swap(a[j], a[j + 1]);
    
    for (int value : a)
        cout << value << " ";
}
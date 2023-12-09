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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> lis(size, 1);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    cout << *max_element(lis.begin(), lis.end());
}
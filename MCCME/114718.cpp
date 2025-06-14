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
    for (int i = 1; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                lis[i] = max(lis[i], lis[j] + 1);

    cout << size - *max_element(lis.begin(), lis.end());
}
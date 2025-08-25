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
    for (int &value : a) {
        cin >> value;
        value--;
    }

    int res = 0;
    vector<int> visited(a.size());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != i && !visited[i]) {
            for (int j = i; !visited[j]; j = a[j]) {
                visited[j] = 1;
                res++;
            }
            res++;
        }
    }

    cout << res;
}
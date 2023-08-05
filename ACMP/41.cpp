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
    scanf("%d", &size);

    vector<int> count(201);
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        count[value + 100]++;
    }

    for (int i = 0; i < count.size(); i++)
        for (int j = 0; j < count[i]; j++)
            printf("%d ", i - 100);
}
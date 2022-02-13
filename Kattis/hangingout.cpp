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

    int limit, queryCount;
    cin >> limit >> queryCount;

    int onTerrace = 0, rejectedGroupCount = 0;
    for (int i = 0; i < queryCount; i++) {
        string query;
        int groupSize;
        cin >> query >> groupSize;

        if (query == "enter") {
            if (onTerrace + groupSize <= limit)
                onTerrace += groupSize;
            else
                rejectedGroupCount++;
        } else {
            onTerrace -= groupSize;
        }
    }

    cout << rejectedGroupCount;
}
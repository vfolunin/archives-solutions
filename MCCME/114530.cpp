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
 
    int deltaArea, prohibitedSize;
    cin >> deltaArea >> prohibitedSize;

    int res = 0;

    for (int outerHeight = 1; outerHeight <= deltaArea; outerHeight++) {
        if (outerHeight == prohibitedSize)
            continue;

        for (int outerWidth = 1; outerWidth <= deltaArea; outerWidth++) {
            if (outerWidth == prohibitedSize)
                continue;

            int innerArea = outerHeight * outerWidth - deltaArea;
            if (innerArea <= 0)
                continue;

            for (int deltaHeight = 1; deltaHeight * outerWidth < deltaArea; deltaHeight++) {
                int innerHeight = outerHeight - deltaHeight;
                if (innerArea % innerHeight)
                    continue;

                int innerWidth = innerArea / innerHeight;
                if (innerWidth < outerWidth)
                    res++;
            }
        }
    }

    cout << res;
}
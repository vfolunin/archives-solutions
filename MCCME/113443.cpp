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

	long long maxLetterWeight, minPackageWeight, minContainerWeight;
	cin >> maxLetterWeight >> minPackageWeight >> minContainerWeight;

	long long maxPackageWeight = minPackageWeight + maxLetterWeight - 1;
	long long packagesInContainer = minContainerWeight / minPackageWeight;

	if (minContainerWeight <= packagesInContainer * maxPackageWeight)
		cout << minContainerWeight;
	else
		cout << (packagesInContainer + 1) * minPackageWeight;
}
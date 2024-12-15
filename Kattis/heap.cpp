#include "heap.h"
#include <set>
using namespace std;

multiset<int> values;

int getMax() {
    return *prev(values.end());
}

int getSize() {
    return values.size();
}

void insert(int value) {
    values.insert(value);
}

void removeMax() {
    values.erase(prev(values.end()));
}

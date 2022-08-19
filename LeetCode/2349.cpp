class NumberContainers {
    unordered_map<int, int> values;
    unordered_map<int, set<int>> indexes;
    
public:
    void change(int index, int value) {
        indexes[values[index]].erase(index);
        if (indexes[values[index]].empty())
            indexes.erase(values[index]);
        values[index] = value;
        indexes[values[index]].insert(index);
    }
    
    int find(int value) {
        return indexes.count(value) ? *indexes[value].begin() : -1;
    }
};
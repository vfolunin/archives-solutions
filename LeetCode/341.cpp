class NestedIterator {
    vector<int> values;
    int index = 0;
    
    void rec(vector<NestedInteger> &v) {
        for (NestedInteger &i : v) {
            if (i.isInteger())
                values.push_back(i.getInteger());
            else
                rec(i.getList());
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        rec(nestedList);
    }
    
    int next() {
        return values[index++];
    }
    
    bool hasNext() {
        return index < values.size();
    }
};
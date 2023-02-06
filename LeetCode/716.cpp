class MaxStack {
    list<int> values;
    map<int, vector<list<int>::iterator>> positions;

public:    
    void push(int value) {
        values.push_back(value);
        positions[value].push_back(prev(values.end()));
    }
    
    int pop() {
        int value = values.back();
        
        values.pop_back();

        positions[value].pop_back();
        if (positions[value].empty())
            positions.erase(value);

        return value;
    }
    
    int top() {
        return values.back();
    }
    
    int peekMax() {
        return prev(positions.end())->first;
    }
    
    int popMax() {
        int value = prev(positions.end())->first;

        auto it = prev(positions.end())->second.back();
        values.erase(it);

        positions[value].pop_back();
        if (positions[value].empty())
            positions.erase(value);

        return value;
    }
};
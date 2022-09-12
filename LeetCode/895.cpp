class FreqStack {
    unordered_map<int, int> count, last;
    map<pair<int, int>, int> values;
    int timer = 0;
    
public:
    void push(int value) {
        count[value]++;
        last[value] = timer++;
        values[{ -count[value], -last[value] }] = value;
    }
    
    int pop() {
        int value = values.begin()->second;
        count[value]--;
        values.erase(values.begin());
        return value;
    }
};
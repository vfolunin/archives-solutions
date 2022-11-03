class DinnerPlates {
    int capacity;
    vector<vector<int>> stacks;
    set<int> notEmpty, notFull;
    
public:
    DinnerPlates(int capacity) : capacity(capacity) {}
    
    void push(int value) {
        if (notFull.empty()) {
            stacks.emplace_back();
            notFull.insert(stacks.size() - 1);
        }
        
        int index = *notFull.begin();
        stacks[index].push_back(value);
        notEmpty.insert(index);
        if (stacks[index].size() == capacity)
            notFull.erase(index);
    }
    
    int pop() {
        if (notEmpty.empty())
            return -1;
        return popAtStack(*notEmpty.rbegin());        
    }
    
    int popAtStack(int index) {
        if (index >= stacks.size() || stacks[index].empty())
            return -1;
        
        int value = stacks[index].back();
        stacks[index].pop_back();
        notFull.insert(index);
        if (stacks[index].size() == 0)
            notEmpty.erase(index);
        return value;
    }
};
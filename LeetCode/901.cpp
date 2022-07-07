class StockSpanner {
    vector<pair<int, int>> stack;
    int index = 0;
    
public:
    StockSpanner() {
        stack.push_back({ 1e9, -1 });
    }
    
    int next(int price) {
        while (stack.back().first <= price)
            stack.pop_back();
        stack.push_back({ price, index });
        index++;
        return stack.back().second - stack[stack.size() - 2].second;
    }
};
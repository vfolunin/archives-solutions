class BrowserHistory {
    vector<string> history;
    int index = 0;
    
public:
    BrowserHistory(string url) : history(1, url) {}
    
    void visit(string url) {
        history.erase(history.begin() + index + 1, history.end());
        history.push_back(url);
        index++;
    }
    
    string back(int steps) {
        index = max(index - steps, 0);
        return history[index];
    }
    
    string forward(int steps) {
        index = min<int>(index + steps, history.size() - 1);
        return history[index];
    }
};
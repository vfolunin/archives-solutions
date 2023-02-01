class Logger {
    unordered_map<string, int> from;

public:
    bool shouldPrintMessage(int timestamp, const string &message) {
        if (auto it = from.find(message); it == from.end() || it->second <= timestamp) {
            from[message] = timestamp + 10;
            return 1;
        }
        return 0;
    }
};
class TaskManager {
    map<pair<int, int>, int> userIdOf;
    unordered_map<int, int> priorityOf;

public:
    TaskManager(vector<vector<int>> &tasks) {
        for (vector<int> &task : tasks)
            add(task[0], task[1], task[2]);
    }
    
    void add(int userId, int taskId, int priority) {
        userIdOf[{ priority, taskId }] = userId;
        priorityOf[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        int priority = priorityOf[taskId];
        int userId = userIdOf[{ priority, taskId }];
        rmv(taskId);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        int priority = priorityOf[taskId];
        int userId = userIdOf[{ priority, taskId }];
        userIdOf.erase({ priority, taskId });
        priorityOf.erase(taskId);
    }
    
    int execTop() {
        if (userIdOf.empty())
            return -1;
        auto [priority, taskId] = prev(userIdOf.end())->first;
        int userId = prev(userIdOf.end())->second;
        rmv(taskId);
        return userId;
    }
};
class Logger {
public:
    // Tu lam
    /** Initialize your data structure here. */
    unordered_map<string, int> hashMap;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto found = hashMap.find(message);
        if(found != hashMap.end()) {
            int time = timestamp - found->second;
            if(time >= 10) {
                hashMap[message] = timestamp;
                return true;
            }
        }
        else {
            hashMap[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
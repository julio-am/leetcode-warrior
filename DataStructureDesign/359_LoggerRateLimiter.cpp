class Logger {

private:
unordered_map<string,int> seen; 

public:
    Logger() {}
    

    bool shouldPrintMessage(int timestamp, string message) {

        if (seen.contains(message) && seen[message] > timestamp-10)
            return false;

        seen[message] = timestamp;
        return true;
    }
};

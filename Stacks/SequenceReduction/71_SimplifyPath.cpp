class Solution {

private:
    // I love c++ but only most of the time.
    vector<string> splitString(string& s) {
        vector<string> result;
        string line;
        stringstream ss(s);
        while (std::getline(ss, line, '/')) {
            result.push_back(line);
        }

        return result;
    }

public:
    string simplifyPath(string path) {
        vector<string> stack;
        vector<string> folders = splitString(path);

        for (auto folder : folders) {
            if (folder == "" || folder == ".") continue;
            if (folder == "..") {
                if (!stack.empty()) stack.pop_back();
            }
            else stack.push_back(folder);
        }

        string result = "";
        for (auto folder : stack) {
            result += '/' + folder;
        } 

        return result.empty() ? "/" : result;
    }
};

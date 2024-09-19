//You are given an array prerequisites where prerequisites[i] = [a, b] indicates that you must take course b first if you want to take course a.
//The pair [0, 1], indicates that must take course 1 before taking course 0.
//There are a total of numCourses courses you are required to take, labeled from 0 to numCourses - 1.
//Return true if it is possible to finish all courses, otherwise return false.

class Solution {
private:
    unordered_map<int, vector<int>> preqMap;
    unordered_set<int> visited;

    // For each course, go through all the dependencies. If we've already seen a depencency
    // return false.
    // If we reach a course with no dependencies, return true.
    bool dfs(int course) {
        if (visited.count(course)) return false;
        if (preqMap[course].empty()) return true;

        visited.insert(course);

        // for each of the prerequites, find the prerequisites..
        for (int preq : preqMap[course]) {
            if (!dfs(preq)) return false;
        }

        visited.erase(course);
        preqMap[course] = {};
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        
        if (prerequisites.empty()) return true;

        for (auto course : prerequisites) {
            preqMap[course[0]].push_back(course[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return false;
        }

        return true;
    }
};

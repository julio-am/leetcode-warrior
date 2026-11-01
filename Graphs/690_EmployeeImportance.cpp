/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {

public:
    int getImportance(vector<Employee*> employees, int id) {
        array<Employee*, 2001> emap{};

        for (auto e : employees) emap[e->id] = e;

        int result = 0;
        queue<Employee*> toVisit;
        toVisit.push(emap[id]);

        while (!toVisit.empty()) {
            auto cur = toVisit.front();
            toVisit.pop();
            result += cur->importance;
            for (auto s : cur->subordinates) toVisit.push(emap[s]);
        }

        return result;
    }
};

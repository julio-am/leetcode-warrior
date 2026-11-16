class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfiable = 0;
        int satisfied = 0;
        
        for (int i = 0; i < minutes; ++i) {
            satisfiable += grumpy[i] * customers[i];
            satisfied += grumpy[i] == 0 ? customers[i] : 0;
        }

        int maxSatisfiable = satisfiable;

        for (int i = minutes; i < customers.size(); ++i) {
            satisfiable += grumpy[i] * customers[i];
            satisfiable -= grumpy[i-minutes] * customers[i-minutes];
            satisfied += grumpy[i] == 0 ? customers[i] : 0;

            maxSatisfiable = max(maxSatisfiable, satisfiable);
        }

        return maxSatisfiable + satisfied;
    }
};

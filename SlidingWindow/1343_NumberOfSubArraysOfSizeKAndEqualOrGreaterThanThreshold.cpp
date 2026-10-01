class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = accumulate(arr.begin(), arr.begin()+k, 0);
        int result = sum >= threshold*k ? 1 : 0;

        for (int i = k; i < arr.size(); ++i) {
            sum -= arr[i-k];
            sum += arr[i];

            result += sum >= threshold*k ? 1 : 0;
        }

        return result;
    }
};

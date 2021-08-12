
//minimum-size-subarray-sum
//Given an array of n positive integers and a positive integer s,
// find the minimal length of a contiguous subarray of which the sum ≥ s.
// If there isn't one, return 0 instead.

int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= s) {
            ans = min(ans, i + 1 - left);
            sum -= nums[left++];
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}
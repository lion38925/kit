class Solution {
public:
int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[366] = {0};
        int index = 0, day = 1;
        dp[days[index]] = min(costs[0], min(costs[1], costs[2]));
        index++;
        for (day = days[0]+1 ; day <= days[n-1] ; day++) {
            if (days[index] == day) {
                int first = dp[day-1]+costs[0];
                int second = (day-7 < 0) ? dp[0]+costs[1] : dp[day-7]+costs[1];
                int third = (day-30 < 0) ? dp[0]+costs[2] : dp[day-30]+costs[2];
                dp[day] = min(first, min(second, third));
                index++;
            }
            else {
                dp[day] = dp[day-1];
            }
        }
        return dp[days[n-1]];
    }
};
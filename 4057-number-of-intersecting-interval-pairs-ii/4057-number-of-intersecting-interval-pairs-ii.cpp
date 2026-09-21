class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        long long count = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &interval : intervals) {
            int start = interval[0];

            while (!pq.empty() && pq.top() < start) {
                pq.pop();
            }

            count += pq.size();
            pq.push(interval[1]);
        }
        return count;
    }
};
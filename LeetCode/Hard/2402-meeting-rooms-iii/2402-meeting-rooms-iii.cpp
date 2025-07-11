class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> freeRooms;
        priority_queue<pair<long long, int>, 
        vector<pair<long long, int>>, greater<>> runningMeetings;
        vector<int> meetingCount(n, 0);
        for(int i = 0; i < n; ++i) freeRooms.push(i);
        
        for(auto &meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            int duration = end - start;

            while(!runningMeetings.empty() && runningMeetings.top().first <= start) {
                int room = runningMeetings.top().second; 
                runningMeetings.pop();
                freeRooms.push(room);
            }

            if(freeRooms.empty()) {
                auto [lastEnd, room] = runningMeetings.top();
                runningMeetings.pop();
                if(lastEnd > start) {
                    runningMeetings.push({lastEnd + duration, room});
                }
                else {
                    runningMeetings.push({end, room});
                }
                meetingCount[room]++;
            }
            else {
                int room = freeRooms.top(); freeRooms.pop();
                runningMeetings.push({end, room});
                meetingCount[room]++;
            }
        }

        return max_element(meetingCount.begin(), meetingCount.end()) - meetingCount.begin();
    }
};
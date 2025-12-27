class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end()); // 3rd rule

        priority_queue<int, vector<int>, greater<>> freeRooms; // smallest rooms
        priority_queue<pair<long long, int>, 
        vector<pair<long long, int>>, greater<>> runningMeetings; // [endTime, room]

        vector<int> meetingCount(n, 0); // hash map for meeting count
        for(int i = 0; i < n; ++i) freeRooms.push(i);
        
        for(auto &meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            int duration = end - start;

            // Freeing up rooms whose meetings have ended
            while(!runningMeetings.empty() && runningMeetings.top().first <= start) {
                int room = runningMeetings.top().second; 
                runningMeetings.pop();
                freeRooms.push(room);
            }

            // If no rooms available -> rule 2
            if(freeRooms.empty()) {
                auto [lastEnd, room] = runningMeetings.top();
                runningMeetings.pop();
                // delay
                if(lastEnd > start) {
                    runningMeetings.push({lastEnd + duration, room});
                }
                // no delay
                else {
                    runningMeetings.push({end, room});
                }
                meetingCount[room]++;
            }
            // free room available
            else {
                int room = freeRooms.top(); freeRooms.pop();
                runningMeetings.push({end, room});
                meetingCount[room]++;
            }
        }

        // STL way to find first maximum index
        return max_element(meetingCount.begin(), meetingCount.end()) - meetingCount.begin();
    }
};
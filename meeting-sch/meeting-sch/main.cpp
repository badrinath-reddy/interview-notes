#include <iostream>

using namespace std;

class TimeSlot {
public:
    int start;
    int end;
    
    bool isConflicting(TimeSlot* timeSlot) {
        // Logic
        return false;
    }
};

class Meeting {
public:
    int meetingId;
    TimeSlot* timeSlot;
    vector<User*> users;
    
    Meeting(int meetingId, TimeSlot* timeSlot) {
        this->meetingId = meetingId;
        this->timeSlot = timeSlot;
    }
};


class User {
    int userId;
    vector<Meeting*> meetings;
    
public:
    User(int userId) {
        this->userId = userId;
    }
    
    bool isConflicting(Meeting* meeting) {
        for(auto x: this->meetings) {
            if (x->timeSlot->isConflicting(meeting->timeSlot)) return true;
        }
        return false;
    }
    
    
    void addMeeting(Meeting* meeting) {
        if(isConflicting(meeting)) {
            throw "conflicting meeting";
        }
        meetings.push_back(meeting);
    }
    
    void printMeetings() {
    
    }
};


class MeetingScheduler {
    vector<User*> users;
    Meeting* meeting;

public:
    MeetingScheduler(vector<User*> users, Meeting* meeting) {
        this->users = users;
        this->meeting = meeting;
    }
    
    bool canSchedule() {
        for(auto &x: users) {
            if(x->isConflicting(this->meeting)) {
                return false;
            }
        }
        return true;
    }
    
    
    bool schedule() {
        for(auto &x: users) {
            x->addMeeting(meeting);
        }
    }
};





int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    return 0;
}

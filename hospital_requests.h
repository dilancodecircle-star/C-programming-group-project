#ifndef HOSPITAL_REQUESTS_H
#define HOSPITAL_REQUESTS_H

#define MAX_RECORDS 100

// Member 4 Structure: Sandapiyum
struct Request {
    int requestID;
    char hospitalName[50];
    char bloodType[5];
    int urgencyLevel; // 1 (Low) to 5 (High)
    char status[20];  // "Pending", "Fulfilled", "Cancelled"
};

// Function Prototypes for Member 4
void logHospitalRequest();
void matchRequestToInventory();
void fulfillRequest();
void cancelRequest();s
void viewHighUrgencyRequests();

#endif // HOSPITAL_REQUESTS_H

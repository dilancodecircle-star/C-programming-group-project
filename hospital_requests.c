#include <stdio.h>
#include <string.h>
#include "hospital_requests.h"

// External dependencies referenced from Member 2's inventory module
struct BloodBag {
    int bagID;
    int donorID;
    char bloodType[5];
    int daysToExpiry;
};
extern struct BloodBag inventory[MAX_RECORDS];
extern int bagCount;

// GLOBAL ARRAYS & COUNTERS FOR MODULE 4
struct Request requests[MAX_RECORDS];
int requestCount = 0;

void logHospitalRequest() {
    if(requestCount < MAX_RECORDS) {
        printf("Enter Request ID: ");
        scanf("%d", &requests[requestCount].requestID);
        printf("Enter Hospital Name: ");
        scanf("%s", requests[requestCount].hospitalName);
        printf("Enter Blood Type Needed: ");
        scanf("%s", requests[requestCount].bloodType);
        printf("Enter Urgency (1-5): ");
        scanf("%d", &requests[requestCount].urgencyLevel);
        strcpy(requests[requestCount].status, "Pending");
        requestCount++;
        printf("Hospital request logged.\n");
    }
}

void matchRequestToInventory() {
    int reqId;
    printf("Enter Request ID to check matches: ");
    scanf("%d", &reqId);
    for(int i = 0; i < requestCount; i++) {
        if(requests[i].requestID == reqId) {
            printf("Searching inventory for %s blood...\n", requests[i].bloodType);
            for(int j = 0; j < bagCount; j++) {
                if(strcmp(inventory[j].bloodType, requests[i].bloodType) == 0 && inventory[j].daysToExpiry > 0) {
                    printf("Match found! Bag ID: %d is available.\n", inventory[j].bagID);
                    return;
                }
            }
            printf("No matching blood available in inventory.\n");
            return;
        }
    }
}

void fulfillRequest() {
    int reqId;
    printf("Enter Request ID to fulfill: ");
    scanf("%d", &reqId);
    for(int i = 0; i < requestCount; i++) {
        if(requests[i].requestID == reqId) {
            strcpy(requests[i].status, "Fulfilled");
            printf("Request marked as fulfilled.\n");
            return;
        }
    }
}

void cancelRequest() {
    int reqId;
    printf("Enter Request ID to cancel: ");
    scanf("%d", &reqId);
    for(int i = 0; i < requestCount; i++) {
        if(requests[i].requestID == reqId) {
            strcpy(requests[i].status, "Cancelled");
            printf("Request cancelled.\n");
            return;
        }
    }
}

void viewHighUrgencyRequests() {
    printf("High Urgency Emergency Requests:\n");
    for(int i = 0; i < requestCount; i++) {
        if(requests[i].urgencyLevel >= 4 && strcmp(requests[i].status, "Pending") == 0) {
            printf("Req ID: %d | Hospital: %s | Type: %s\n", requests[i].requestID, requests[i].hospitalName, requests[i].bloodType);
        }
    }
}

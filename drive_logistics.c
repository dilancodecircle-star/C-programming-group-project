#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 100

// =========================================================================
// 1. STRUCTURE DEFINITIONS
// =========================================================================

struct DonationEvent
{
    int eventID;
    char venue[50];
    int goalUnits;
    int gatheredUnits;
    char scheduleDate[15];
};

// =========================================================================
// GLOBAL ARRAYS & COUNTERS
// =========================================================================

struct DonationEvent events[MAX_EVENTS];
int eventCount = 0;

// =========================================================================
// FUNCTION PROTOTYPES
// =========================================================================

void addEvent();
void recordUnits();
void removeEvent();
void highlightTopEvent();
void showUpcomingEvents();

int main()
{
    int choice;

    while (1)
    {
        printf("\n======================================================\n");
        printf(" Community Blood Donation & Matching System \n");
        printf("======================================================\n");
        printf("1. Donor Registry          \n");
        printf("2. Inventory & Storage     \n");
        printf("3. Testing & Screening     \n");
        printf("4. Hospital Requests       \n");
        printf("5. Event Logistics         \n");
        printf("6. Exit System\n");
        printf("Enter module number to access: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n--- Not Available ---\n");
            break;
        case 2:
            printf("\n--- Not Available ---\n");
            break;
        case 3:
            printf("\n--- Not Available ---\n");
            break;
        case 4:
            printf("\n--- Not Available ---\n");
            break;
        case 5:
        {
            printf("\n--- Not Available ---\n");
            break;
        }
        case 6:
            printf("Exiting system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
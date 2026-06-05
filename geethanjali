#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 100   // define array


struct DonationEvent // making structure for donation
{
    int eventID;
    char venue[50];
    int goalUnits;
    int gatheredUnits;
    char scheduleDate[15];
};



struct DonationEvent events[MAX_EVENTS]; // define array for structure
int eventCount = 0;



void addEvent();
void recordUnits();
void removeEvent();
void highlightTopEvent();
void showUpcomingEvents();

int main()  //main function
{
    int choice , n=1;

    while (n)
    {
        printf("\n======================================================\n");
        printf("Decentralized Blood Banking System \n");
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
  
        case 5:
        
            int subChoice;
            printf("\n--- Event Logistics ---\n");
            printf("1. Add Event\n2. Record Units\n3. Remove Event\n4. Highlight Top Event\n5. Show Upcoming\nSelect: ");
            scanf("%d", &subChoice);
            if (subChoice == 1){
                addEvent();
            }
            else if (subChoice == 2){
                recordUnits();
            else if (subChoice == 3){
                removeEvent();
            }
            else if (subChoice == 4){
                highlightTopEvent();
            }
            else if (subChoice == 5){
                showUpcomingEvents();
            }
            break;
        
        case 6:
            printf("Exiting system. Goodbye!\n");
            n=0;
            continue;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addEvent() //This function for add a new event
{
    if (eventCount < MAX_EVENTS)
    {
        printf("Enter Event ID: ");
        scanf("%d", &events[eventCount].eventID);
        printf("Enter Venue: ");
        scanf("%s", events[eventCount].venue);
        printf("Enter Date (DD-MM-YYYY): ");
        scanf("%s", events[eventCount].scheduleDate);
        printf("Enter Goal Units: ");
        scanf("%d", &events[eventCount].goalUnits);
        events[eventCount].gatheredUnits = 0;
        eventCount++;
        printf("Event added successfully.\n");
    }
}

void recordUnits()  //This function for update the total amount of blood collected for a specific camp as donation come in.
{
    int eId, units;
    printf("Enter Event ID: ");
    scanf("%d", &eId);
    printf("Enter newly gathered units: ");
    scanf("%d", &units);
    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].eventID == eId)
        {
            events[i].gatheredUnits += units;
            printf("Total units gathered for event %d: %d\n", eId, events[i].gatheredUnits);
            return;
        }
    }
}

void removeEvent()  //This function for cancel a sheduled blood donation camp.
{
    int eId;
    printf("Enter Event ID to remove: ");
    scanf("%d", &eId);
    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].eventID == eId)
        {
            events[i].goalUnits = -1;
            printf("Event removed.\n");
            return;
        }
    }
}

void highlightTopEvent()  //This function for find and display the most successful blood donation camp
{
    int topIndex = 0;
    int maxUnits = -1;
    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].gatheredUnits > maxUnits)
        {
            maxUnits = events[i].gatheredUnits;
            topIndex = i;
        }
    }
    if (maxUnits >= 0)
    {
        printf("Top event was at %s with %d units gathered.\n", events[topIndex].venue, maxUnits);
    }
    else
    {
        printf("No events recorded yet.\n");
    }
}

void showUpcomingEvents()  //This function for display a list of all the active,upcoming blood donation camps
{
    printf("Upcoming Donation Events:\n");
    for (int i = 0; i < eventCount; i++)
    {
        if (events[i].goalUnits > 0)
        {
            printf("Date: %s | Venue: %s | Goal: %d units\n", events[i].scheduleDate, events[i].venue, events[i].goalUnits);
        }
    }
}

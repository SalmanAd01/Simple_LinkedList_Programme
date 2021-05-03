#include <stdio.h>
int LINK[20];         //lt represent the data in the node
int LIST[20];         //represent the pointer which gonna point to another node
int PTR;              //to track the pointer
int START;            //where to start the list
int location(int num) //to get the position of that number in link
{
    PTR = START;
    int l = -2;
    while (PTR != -1)
    {
        if (num == LIST[PTR])
        {
            l = PTR;
            break;
        }
        else
        {
            PTR = LINK[PTR];
        }
    }

    return (l);
}
int main()
{
    int num;     //to get the number from the user for which the opretions are gonna performed
    int loc;     //to store the location
    int l;       //to store the old link which we gonna need to perform case number 1
    int choice;  //to store the choice of the store which we gonna use in switch case statements
    int new;     //to store the number present in the list which we gonna use in replace case
    int present; //for checking if number is present in the list or not (replace case)
    LIST[0] = 22;
    LIST[2] = 5;
    LIST[3] = 19;
    LIST[5] = 87;
    LIST[7] = 29;
    LIST[8] = 79;
    LIST[9] = 33;
    LIST[11] = 2;
    LIST[13] = 50;
    LIST[14] = 8;
    LIST[16] = 55;
    LIST[18] = 99;
    LINK[0] = 3;
    LINK[2] = 13;
    LINK[3] = 2;
    LINK[5] = 8;
    LINK[7] = 14;
    LINK[8] = 9;
    LINK[9] = 18;
    LINK[11] = 16;
    LINK[13] = 5;
    LINK[14] = -1;
    LINK[16] = 0;
    LINK[18] = 7;
    START = 11;
    PTR = START;
    printf("\nTHE LIST IS GIVEN BY\n"); //to print the originoal link list
    while (PTR != -1)
    {
        printf("%d\t", LIST[PTR]);
        PTR = LINK[PTR];
    }
    PTR = START;
    printf("\nEnter the number who you wanated to add in the list\n");
    scanf("%d", &num);
    printf("NOTE: THE REMAINING FREE POSITIONS ARE 1,4,6,10,12,15,17\n");
    printf("Enter 1 if you wanted to add your number in this positions\n");
    printf("Enter 2 if you wanted to add your number in the beginnig\n");
    printf("Enter 3 if you wanted to add your number a the end of the list\n");
    printf("Enter 4 if you wanted to replace number\n");
    scanf("%d", &choice);
    switch (choice) //to execute the choice number inputed by the user
    {
    case 1:
        printf("Enter it's position as well\n");
        scanf("%d", &loc);
        l = LINK[(loc - 1)];
        LINK[(loc - 1)] = loc;
        LIST[(loc)] = num;
        LINK[(loc)] = l;
        break;
    case 2:
        PTR = 10;
        LIST[10] = num;
        LINK[10] = 11;
        break;
    case 3:
        LINK[14] = 15;
        LIST[15] = num;
        LINK[15] = -1;
        break;
    case 4:
        printf("Enter which number from the list you wanted to replace\n");
        scanf("%d", &new);
        present = location(new);
        if (present == -2)
        {
            printf("you have entered a number which doesn't exist in the given list\n");
            loc=-1;
        }
        else
        {
            LIST[present] = num;
        }
        PTR = START;

        break;

    default:
        printf("you have entered invalid options\n");
        loc = -1;
        break;
    }

    if (loc != -1)
    {
        printf("THE LIST IS AFTER ADDING NEW NUMER IS GIVEN BY\n");
        while (PTR != -1)
        {
            printf("%d\t", LIST[PTR]);
            PTR = LINK[PTR];
        }
    }

    return 0;
}
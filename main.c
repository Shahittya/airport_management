#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct User
{
    char username[20];
    char password[10];
    char fullname[30];
    char phone[13];

};
struct Flights
{
    char flightNo[20];
    char from[20];
    char destination[20];
    char jdate[20];
    char adate[20];
    char time[10];
    int seats;
    int price
};
struct Person
{
    char fname[20];
    char lname[20];
    char phone[13];
    char passport[20];
    char from[20];
    char to[20];
    int payment_method;
    int price;
    char payment_status[];
};

struct Person passenger[100];


struct User users[]=
{
    {"yash","123","yash siddque shahittya","01705915192"},
    {"kazi","abc123","kazi nazrul islam","0160643246"},
    {"batman","batcave","bruce wayne","0137464733"}
};
struct User admin[]=
{
    {"superman","sup123","clark kent","0173464743"},
    {"iron","123iron","Tony Stark","01237363287"}
};
struct Flights flight[]=
{
    {"A01","k","d","2023-03-05","2023-03-06","13:00",45,200},
    {"J22","pekan","kulalampur","2023-03-06","2023-03-07","10:00",80,400},
    {"K21","johorbharu","uae","2023-03-07","2023-03-09","19:00",121,180},
    {"K25","a","b","2023-05-07","2023-07-09","20:00",0,600}
};
//authentication for the user
bool loginUser(char username[],char password[])
{
   for(int i=0;i<sizeof(users)/sizeof(users[0]);i++)
   {
       if(strcmp(username,users[i].username)==0 && strcmp(password,users[i].password)==0)
       {
           return true;
       }
   }
   return false;
}
//authentication for the admin
bool adminUser(char username[],char password[])
{
   for(int i=0;i<sizeof(admin)/sizeof(admin[0]);i++)
   {
       if(strcmp(username,admin[i].username)==0 && strcmp(password,admin[i].password)==0)
       {
           return true;
       }
   }
   return false;

}

void showFlights()
{

    for(int i=0;i<sizeof(flight)/sizeof(flight[0]);i++)
    {

        printf("SERIAL NO.%d\n",i+1);
        printf("FLIGHT NO.%s\n",flight[i].flightNo);
        printf("JOURNEY FROM-%s\n",flight[i].from);
        printf("DESTINATION-%s\n",flight[i].destination);
        printf("START DATE:%s\n",flight[i].jdate);
        printf("TIME(LOCAL TIME):%s\n",flight[i].time);
        printf("ARRIVAL DATE:%s\n",flight[i].adate);
        printf("SEATS AVAILABLE:%d\n",flight[i].seats);
        printf("TICKET PRICE: %d RM\n",flight[i].price);
        printf("\n");
        printf("\n-------------------------------------------\n\n");


    }
}

char searchFlight(char from[],char to[])
{
    int flag=0;
    for(int i=0;i<sizeof(flight)/sizeof(flight[0]);i++)
    {
        if(strcmp(from,flight[i].from)==0 && strcmp(to,flight[i].destination)==0)
        {
        flag=1;
        printf("\n");
        printf("FLIGHT FOUND!!\n");
        printf("SERIAL NO. %d\n",i+1);
        printf("FLIGHT NO. %s\n",flight[i].flightNo);
        printf("JOURNEY FROM- %s\n",flight[i].from);
        printf("DESTINATION- %s\n",flight[i].destination);
        printf("START DATE: %s\n",flight[i].jdate);
        printf("TIME(LOCAL TIME): %s\n",flight[i].time);
        printf("ARRIVAL DATE: %s\n",flight[i].adate);
        printf("SEATS AVAILABLE: %d\n",flight[i].seats);
        printf("\n");


        }

}
if(flag!=1)
{
    printf("\n");
    printf("\nSorry!...No Flight Available!\n");
    printf("\n");
}
}
bool seatBooked(char from[],char to[])
{
    for(int i=0;i<sizeof(flight)/sizeof(flight[0]);i++)
    {
        if(strcmp(from,flight[i].from)==0 && strcmp(to,flight[i].destination)==0 )
        {
            return true;
        }
    }
    return false;
}
void FindUser(char name[])
{
    int flag=0;
    for(int i=0;i<sizeof(users)/sizeof(users[0]);i++)
    {
          if(strcmp(name,users[i].username)==0)
          {
              printf("\n************User Found************\n");
              printf("UserName: %s\n",users[i].username);
              printf("Full Name: %s\n",users[i].fullname);
              printf("Phone Number: %s\n",users[i].phone);
              printf("\n------------------------------\n");
              flag=1;
          }
    }
    if(flag!=1)
    {
        printf("\nUser Not Found!\n");
    }

}

void changePassword(name)
{
    int flag=0;
    for(int i=0;i<sizeof(users)/sizeof(users[0]);i++)
    {
        if(strcmp(name,users[i].username)==0)
        {
            flag=1;
            printf("Enter New Password \n");
            char passcode[10];
            scanf("%s",&passcode);
            strcpy(users[i].password,passcode);
            printf("Password Updated\n");
            printf("\n");
        }
    }
}
void deleteUser(name)
{
    int foundIndex=-1;
    for(int i=0;i<sizeof(users)/sizeof(users[0]);i++)
    {
        if(strcmp(name,users[i].username)==0)
        {
            foundIndex=i;
            break;
        }
    }

    if(foundIndex!=-1)
    {
          for(int i=foundIndex;i<sizeof(users)/sizeof(users[0])-1;i++)

    {

        users[i]=users[i+1];
    }
 printf("\nUser Deleted Permanently\n");
    }else{
    printf("User Not Found!!\n");
    }
}
void findPassenger(char name[])
{
    for(int i=0;i<sizeof(passenger)/sizeof(passenger[0]);i++)
    {
        if(strcmp(name,passenger[i].fname)==0)
        {
            printf("\n");
            printf("First Name: %s\n",passenger[i].fname);
            printf("Last Name: %s\n",passenger[i].lname);
            printf("Phone Number: %s\n",passenger[i].phone);
            printf("Passport Number: %s\n",passenger[i].passport);
            printf("From: %s\n",passenger[i].from);
            printf("Destination: %s\n",passenger[i].to);
            printf("Total: %d RM\n",passenger[i].price);
            printf("Payment Method(1.Cash 2.Card): %d\n",passenger[i].payment_method);
            printf("payment Status: %d\n",passenger[i].payment_status);
        }
    }
}

int main()
{

    printf("-------------------------Welcome To XYZ Airport's System-------------------------\n");
    printf("\n");
    while(true)
    {


        printf("Please Select Or User Mode-\n1.Staff\n2.Admin\n");
        int choice;
        scanf("%d",&choice);
        printf("\n");
        while (getchar() != '\n') ; //for clearing the input buuffer
        if(choice==1)
        {


            printf("Welcome User!!!\n\n-------Enter Your Login Credentials-------\n\n");
            char username[20];
            char password[10];
            printf("Enter Your Username: ");
            scanf("%s",&username);

            printf("Enter Your Password: ");
            scanf("%s",&password);
            if(loginUser(username,password))
            {
                printf("\n");
                printf("Authentication Successful\nYou Have Successfully Logged Into The System\n\n");
                int loggedIn=1;
                while(loggedIn)
                {

                     printf("--------Select Any Option--------\n1.Show All Flights Available\n2.Search Flight\n3.Reserve Flight\n4.Logout\n");
                      printf("\n----------------------------------------------------------\n");
                     int decision;
                     scanf("%d",&decision);
                     if(decision==1)
                     {
                         printf("\n*************************AVAILABLE FLIGHTS*************************\n");
                         showFlights();

                     }else if(decision==2)
                     {
                         printf("\nSEARCH YOUR DESIRE FLIGHT.......\n");
                         printf("\nFrom: ");
                         char from[20];
                         scanf("%s",&from);
                         printf("To: ");
                         char to[20];
                         scanf("%s",&to);
                         searchFlight(from,to);


                     }else if(decision==3)
                     {

                         char from[20];
                         char to[20];
                         printf("From: ");
                         scanf("%s",from);
                         printf("To: ");
                         scanf("%s",to);
                         if(seatBooked(from,to))
                         {

                            printf("\nFlights Available\n");
                            for(int i=0;i<sizeof(flight)/sizeof(flight[0]);i++)
                            {
                                if(strcmp(from,flight[i].from)==0 && strcmp(to,flight[i].destination)==0)
                                {
                                    int flag=0;
                                    if(flight[i].seats>0)
                                    {
                                         flag=1;
                                          printf("\n\nSeats Available: %d\n\n",flight[i].seats);
                                         printf("\nFlight(s) Serial: %s\n",flight[i].flightNo);
                                         printf("Do You Want To Book Any Seat In This Flight-\n1.Yes\n2.No\n");
                                         flight[i].seats-=1;
                                         int decs;
                                        scanf("%d",&decs);
                                         if(decs==1)
                                         {
                                     printf("Please Fill Up The Queries To Make Your Booking\n");
                                     printf("Enter Your Personal Details To Make The Purchase Successful\n");
                                     char fname[20];
                                     char lname[20];
                                     char phone[13];
                                     char passport[20];

                                     strcpy(flight[i].from,flight[i].from);
                                     strcpy(flight[i].destination,flight[i].destination);
                                     int price=flight[i].price;
                                     printf("Enter Passenger First Name: \n");
                                     scanf("%s",passenger->fname);
                                     printf("Enter Passenger Last Name: \n");
                                     scanf("%s",passenger->lname);
                                     printf("Enter Passenger Contact Info: \n");
                                     scanf("%s",passenger->phone);
                                     printf("Enter Passenger Passport Info: \n");
                                     scanf("%s",passenger->passport);
                                     printf("\n------User Details Saved------\n\n");
                                     int flag=1;
                                     while(flag)
                                     {
                                        printf("\n1.Choose Class\n2.Add Meal\n3.Extra Baggages\n4.Payment\n5.Go To Main Menu\n\n");
                                         int choice;
                                         scanf("%d",&choice);
                                         if(choice==1)
                                         {
                                             printf("Choose Any Class\n1.Buisness Class(extra 80 RM)\n2.Super-Economy Class(extra 40 RM)\n3.Economy Class\n");
                                             int choice;
                                             scanf("%d",&choice);
                                             if(choice==1)
                                             {
                                                 price+=80;
                                             }else if(choice==2)
                                             {
                                                 price+=40;
                                             }
                                             else
                                             {
                                                 price+=0;
                                             }


                                         }
                                         else if(choice==2)
                                         {
                                             printf("\nFor Adding Per Meal You Might Charge 12 RM\nEnter The Quantity Of Meal\n");
                                             int quantity;
                                             scanf("%d",&quantity);
                                             int calc1=12*quantity;
                                             price+=calc1;

                                         }
                                         else if(choice==3)
                                         {
                                             printf("Passenger Can Carry 37 kg's\nFor Extra Per Kg You Will Be Charged 10 RM Per Kg\n");
                                             printf("Enter Extra Quantity\n");
                                             int quantity;
                                             scanf("%d",&quantity);
                                             int calc=10*quantity;
                                             price+=calc;
                                         }
                                         else if(choice==4)
                                         {
                                             printf("---------\n");
                                             printf("\nTotal Price: %d\n",price);
                                             printf("Are You Sure You Want To Go To The Payment Method\n1.Yes\n2.No\n");
                                             int decision;
                                             scanf("%d",&decision);
                                             if(decision==1)
                                             {
                                                 printf("\nTotal Price: %d\n",price);
                                                 passenger->price=price;
                                                 printf("Enter Payment Method\n1.Cash\n2.Card\n");
                                                 int decs;
                                                 scanf("%d",&decs);
                                                 printf("\nWait!Confirming Your Payment....\n");
                                                 passenger->payment_method=decs;
                                                 strcpy(passenger->payment_status,"done");


                                             }
                                             else
                                             {
                                                 flag=0;
                                             }

                                         }
                                         else if(choice==5)
                                         {
                                             flag=0;
                                             printf("\n");
                                         }
                                         else
                                         {
                                             printf("\nInput Validation Error\n");
                                             continue;
                                         }
                                     }

                                         }else
                                         {
                                             printf("Keep Searching For Flights\n\n");
                                         }

                                    }
                                    else
                                    {
                                        printf("\n");
                                        printf("\nSeats Are Not Available\n\n");
                                        flag=0;
                                    }
                                }
                            }

                         }else
                         {
                             printf("\n Sorry!!..No Flights Available Right Now..\n");
                         }


                     }

                     else if(decision==4)
                     {
                         printf("\nLogged Out Successfully\n");
                         printf("\n");

                         loggedIn=0;
                     }else
                     {
                         loggedIn=0;
                         printf("\nInput Not Validate!....\n");
                         printf("Logging Out Automatically From The System\n");
                         //loggedIn=0;
                     }
                }

            }
            else
            {
                printf("Something Went Wrong\n");
                printf("\n");
            }

        }
        else if(choice==2)
        {
            printf("Welcome Admin!!!\n\n-------Enter Your Login Essentials-------\n\n");
            printf("Enter Your Username: ");
            char username[20];
            scanf("%s",&username);
            char password[10];
            printf("Enter Your Password: ");
            scanf("%s",password);
            if(adminUser(username,password))
            {
                printf("Authentication Successful\nYou Have Successfully Logged Into The System As An Admin\n\n");
                int loggedIn=1;
                while(loggedIn)
                {
                    printf("\n----------SELECT ANY OPTION----------\n\n1.Show User Information\n2.Show Passenger Information\n3.Change Password(USER)\n4.Delete User\n5.Logout\n\n");
                    printf("\n---------------------------------\n");
                    int decs;
                    scanf("%d",&decs);
                    if(decs==1)
                    {
                     printf("---Search User Information By Name---\n");
                     printf("Enter User Name: \n");
                     char name[20];
                     scanf("%s",&name);
                     FindUser(name);
                     printf("\n");
                    }else if(decs==2)
                    {
                        printf("************Find Passenger************\n");
                        printf("Enter Passenger's First Name \n");
                        char name[30];
                        scanf("%s",&name);
                        findPassenger(name);

                    }else if(decs==3)
                    {
                        printf("---Reset User's Password---\n");
                        printf("Enter User Name(username)");
                        char name[20];
                        scanf("%s",name);
                        printf("A Reset Link Sent To User's Phone Number\nClick To Confirm The Request\n");
                        printf("Waiting For Confirmation\n");
                        changePassword(name);

                    }else if(decs==4)
                    {
                        printf("--Remove User From Employee List--\n");
                        char name[20];
                        printf("Enter Username: ");
                        scanf("%s",&name);
                        deleteUser(name);

                    }else
                    {
                        printf("\nSuccessfully!..Logging Out!!\n\n");
                        loggedIn=0;
                    }

                }

            }
            else
            {
                printf("\n");
                printf("Something Went Wrong...\nTry Re-Entering Username And Password!\n");
                printf("\n");

            }
        }
        else
        {
            printf("Invalid Input!!!\nTry Entering Valid Format Of Data Or Choose The Right Option!.....\n\n\n");
            continue;
        }
    }


}

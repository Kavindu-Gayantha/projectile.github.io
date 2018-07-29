/*
Author: S.K.G.C.Ariyarathna
Purpose: completing tutorial 4
Date created: 27 jul 2018
Date of last modified: 29 jul 2018
*/
#include<stdio.h>
#include<math.h>
#include<time.h>
//function prototype
int welcome();
int target();
int user_inputs();
int converting();
float distance();
int shot_distance();

float velocity,angle,radians,distance1,distance2,target_distance,shoot1,shoot2;//global variables

int main()
{
    char repeat;
  do{
    int x;
    for(x=0;x<100;x++)
    {
        printf("*");
        printf("*");
    }
    printf("\n");
    welcome(); //welcome msg and explaining the rules
    target(); // display the target to the user

    user_inputs();//getting velocity and angle from the user
    converting(); //converting degrees into radians
    distance();//displaying distance
    shot_distance();//measuring weather projectile is reaching to the point within 10% to the real distance or not
    if(angle<180 && angle > 0 && velocity>0)
    {


    if(distance2<=shoot1 && distance2>=shoot2)
    {
        printf("\nCongratulations!! YOU WON!1\n\n");
    }
    else
    {
        printf("\nsorry,YOU FAILED, try again\n");
        if(distance2<shoot1)
        {
            printf("\nToo short\n");
        }
        else
        {
            printf("\nToo long\n");
        }
    }
    }
    printf("\nIf you want to continue this program, then enter 'y' , if not then press anything else\n");
    scanf(" %c",&repeat);
}while(repeat=='y');
}

int welcome()
{
    printf("\nWELCOME to the new program\nThis is a program for launching a projectile at a target.The target will appear somewhere between 1500 meters to 2000 meters away from the launch site.\n");
    printf("This program will prompt the user to enter the angle and the velocity for launching the projectile.\n");
    printf("You would win if your shoot is landed within 10 percent of distance to the target point\n\n");

return 0;
}

int target()
{   target_distance=rand()%500+1500;
    printf("\nYour target is %.2f meters away from the point where shot the object\n\n",target_distance);
 return 0;
}

int user_inputs()
{
   printf("\nEnter velocity here in meters per second : ");
   scanf("%f",&velocity);
   printf("\nEnter angle here in degrees : ");
   scanf("%f",&angle);
   if(angle>180 || angle < 0|| velocity<0)
   {
       printf("\nInvalid inputs, plz consider about the angle and the velocity you input\n velocity should be only positive values and the angle should be between 0 to 180 degrees\n\n");
   }
return velocity;
}

int converting()
{
    radians=(angle*3.1415926)/180.00;
return radians;
}

float distance()
{
    distance1= velocity*velocity*sin(2*radians);
    distance2=distance1/32.2;

    printf("\nDistance of the shoot with the velocity and the angle that you have given is : %.2f",distance2);


return distance2;
}

int shot_distance()
{
    shoot1=target_distance-target_distance/10;// 10% short
    shoot2=target_distance+target_distance/10;// 10% long

return shoot1,shoot2;
}

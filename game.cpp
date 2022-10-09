#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void question(int a, int b)
{
    printf("\nHow much is %d times %d? ",a,b);
}
int main()
{   
    int level,upper,lower=0,a,b,total,correct=0,incorrect=0;
    reset:
    cout<<"Welcome to LEARN MULTIPLICATION!"<<endl;
    choice:
    cout<<"To continue press 'y' or to quit press 'n' : ";
    char c;
    cin>>c;
    switch (c)
    {
    case 'y' :
        break;
    case 'n' :
        return 0;
    default:
        cout<<"Please enter valid command\n";
        goto choice;
    }
    diff:
    cout<<"Enter difficulty level (1 to 3) ";
    cin>>level;
    here:
    switch(level)
    {
        case 1:
            upper=9;
            break;
        case 2:
            upper=99;
            break;
        case 3:
            upper=999;
            break;
        default:
            cout<<"Enter valid difficulty level!"<<endl;
            goto diff;
    }
    
    correct=0,incorrect=0;
    while((correct+incorrect)!=10)
  { 
    srand(time(0));
    a=rand()%(upper-lower+1)+lower;
    b=rand()%(upper-lower+1)+lower;
    repeat:
    question(a,b);
    int answer;
    cin>>answer;
    if(answer==(a*b))
    {   
        correct++;
        int i=(rand()%(4-1+1))+1;
        switch(i)
        {
            case 1:
                cout<<"Very good!"<<endl;
                break;
            case 2:
                cout<<"Excellent!"<<endl;
                break;
            case 3:
                cout<<"Nice work!"<<endl;
                break;
            case 4:
                cout<<"Keep up the good work!"<<endl;
                break;
        }
    
    }

    else if(answer!=(a*b))
    {   incorrect++;
        if((correct+incorrect)!=10)
        {int j=(rand()%(4-1+1))+1;
        switch(j)
        {
            case 1:
                cout<<"No. Please try again."<<endl;
                break;
            case 2:
                cout<<"Wrong. Try once more."<<endl;
                break;
            case 3:
                cout<<"Don't give up!"<<endl;
                break;
            case 4:
                cout<<"No. Keep trying!"<<endl;
                break;
        }
        }
            if((correct+incorrect)!=10)
                goto repeat;
    }
  }
    float percentage=(correct/10.0)*100;
    cout<<"\n Your percentage is :"<<percentage<<"%"<<endl;
    if(percentage<75)
        cout<<"\n Please ask your teacher for extra help."<<endl;
    else if(percentage>=75)
       { cout<<"Congratulations, you are ready to go to the next level!"<<endl;
            if(level<4)
               { level++;
                goto here;
               }
        }
        cout<<endl<<"Thanks for participating!"<<endl<<endl<<"Resetting the program for next student..."<<endl<<endl;
        goto reset;
        return 0;
  }



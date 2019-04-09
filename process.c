#include<stdio.h>
#include<math.h>
#include<string.h>
//#include<unistd.h>
#define N 4
#define ACTIVE 0
#define NONACTIVE 1
#define PROCESSED 2

char process[N][3]={"P1","P2","P3","P4"};
int AT[N]={0,5,13,17};
int BT[N]={20,36,19,42};
int State[N]={NONACTIVE,NONACTIVE,NONACTIVE,NONACTIVE};//this is for the keeping the state of the all processes
float PriorityRelative[N];

//now defining the final tables
char Processed[N][3];
int timer[N];
int next=-1;//this is for the keeping the processed index initialize it to -1 so when increase to it become 0

int timeKeeper=0;//this for the tracking the time of process

void PriorityCalculator(){
    
      for(int i=0;i<N;i++){//printf("initial priority is %f for process %s \n",PriorityRelative[i],process[i]);
         if(State[i]==ACTIVE){PriorityRelative[i]=1+fabs(timeKeeper-AT[i])/BT[i];}
         else if(State[i]==PROCESSED){PriorityRelative[i]=-1;}
         else if(State[i]==NONACTIVE){PriorityRelative[i]=0;}
        //  printf("priority number final %f for process %s  \n\n",PriorityRelative[i],process[i]);
        //now we can manage priority easily

    }
}

void HigherPriorityProcess(){
    float maxKeeper=0;//for the track of the max priority number
    int indexKeeper=-1;//for the track of the index
    for(int i=0;i<N;i++){
        if(State[i]==ACTIVE){
            if(PriorityRelative[i]>maxKeeper){
                maxKeeper=PriorityRelative[i];
                
                indexKeeper=i;
            }
        }
    }

    if(maxKeeper>0){next++;//printf("\n\n\n\n %f  and index %d",maxKeeper,indexKeeper);
        PriorityRelative[indexKeeper]=-1;//means that process is being processed
        timer[next]=timeKeeper+BT[indexKeeper];
        timeKeeper=timer[next];
        strcpy(Processed[next],process[indexKeeper]);
        State[indexKeeper]=PROCESSED;//after processing the process marking as processed
        
    }
}

void ProcessActivator(){
for(int i=0;i<N;i++){
        if(AT[i]<=timeKeeper&&State[i]==NONACTIVE){State[i]=ACTIVE;
            //now all process has become active
                }
        // printf("process %s has state %d \n",process[i],State[i]); 
    }
     for(int i=0;i<N;i++){
        if(State[i]==ACTIVE||State[i]==NONACTIVE){PriorityCalculator();
    HigherPriorityProcess();}
    }
}

void averageWaitingTime(){
    float avg=0;
    int waittingTime=0;
    for(int i=0;i<N;i++){waittingTime=timer[i]-BT[i]-AT[i];
            
        if(waittingTime<=0){avg=avg;
            printf("process %s has waiting time %d\n",Processed[i],waittingTime);
            
        }else{ printf("process %s has waiting time %d \n",Processed[i],waittingTime);
                 avg=avg+waittingTime;
        }
       

    }
    printf("Average waiting time is %f \n",avg/N);
}

int main(){for(int i=0;i<N;i++){
        printf("Process %s Arrivaltime %d and BurstTime %d",process[i],AT[i],BT[i]);
    }
    printf("\n\n\n");

    float avgTurn=0;
    for(int i=0;i<N;i++){
        ProcessActivator();
    }
    
    
   averageWaitingTime();
   printf("\n\n\n");
    for(int i=0;i<N;i++){
        // printf("process %s and processed at %d \n",Processed[i],timer[i]);
        printf("process %s has turnaround time %d \n",Processed[i],timer[i]-AT[i]);
        avgTurn=avgTurn+timer[i]-AT[i];
        

    }
    printf("Average turnaround time is %f \n",avgTurn/N);

       
   
    return 0;
}
//now we have to find waiting time and turnaround time and average waiting time and avg turnaround time]]]]]]


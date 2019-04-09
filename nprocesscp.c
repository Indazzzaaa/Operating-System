#include<stdio.h>
#include<math.h>
#include<string.h>
#define n2 4
#define ACTIVE 0
#define NONACTIVE 1
#define PROCESSED   2
int N;
int n1=4;

char Pname[n2][3]={"P1","P2","P3","P4"};
int State[n2]={NONACTIVE,NONACTIVE,NONACTIVE,NONACTIVE};
int AT[n2]={0,2,3,8};
int BT[n2]={10,7,18,12};
int NBT[n2]={10,7,18,12};
int TotalBT=10+7+18+12+n2-1;
int turnAround[n2];
int timer=-1;
int ET[n2];//this will track the end time of the process

int indexKeeper;//to keep track the index of currently executing process
int counter;//to count times process has been finished



//this will bring the process in active state
void ActivateTheProcess(int time){                                          
for(int i=0;i<N;i++){
    if(State[i]==NONACTIVE){
        if(AT[i]<=timer){State[i]=ACTIVE;
        }
    }
   
}

   
}

//now keep track to the process which have to process as time proceeds
void Proceeds(){
    int prioritizer=10000;//any dummy number which seems as infinity
    for(int i=0;i<N;i++){
        if(State[i]==ACTIVE){
            int temp=BT[i];
            if(prioritizer>temp){
                prioritizer=temp;
                indexKeeper=i;
            }
        }
    }
    ProcessedTheProcess(indexKeeper,timer);
    
}


//this will see wheter process has been finished or in executing state
void ProcessedTheProcess(int index,int thistimer){
    if(BT[index]!=0){BT[index]=BT[index]-1;//this will decrease the burst time of the active process as timer goes

    }
    else if(BT[index]==0&&State[index]!=PROCESSED){
        State[index]=PROCESSED;
        ET[index]=thistimer-counter;
        counter++;
        
    }
}
void averageWaitingTime(){
    float avg=0;
    int waittingTime=0;
    for(int i=0;i<N;i++){waittingTime=ET[i]-NBT[i]-AT[i];
            
        if(waittingTime<=0){
            avg=avg;
        }else{
                 avg=avg+waittingTime;
        }
       

    }
    printf("Average waiting time is %f \n",avg/N);
}



int main(){int decider=0;
 float turnar=0;
    printf("Enter 1 to look at the default use case and enter 2 for using manually by entring");
    scanf("%d",&decider);
    


    if(decider==1){
        
N=n1;
    for(int i=0;i<TotalBT+12;i++){
        timer=i; 
        ActivateTheProcess(i);
        Proceeds();
       
    }
    // for(int i=0;i<N;i++){
    //     printf("%d\n",ET[i]);
   

        
     }
     //averageWaitingTime();
     


    //###################################################################################################################
    //####################################################################################################################

    else if(decider==2){N=n1;
        printf("Enter the number of process you want");
        scanf("%d",&n1);
        TotalBT=0;
        for(int i=0;i<n1;i++){
            printf("Enter the process eg. P1 and the arrival time and BurstTime");
            scanf("%s %d %d",&Pname[n1],&AT[i],&BT[i]);
            State[i]=NONACTIVE;
            TotalBT=TotalBT+BT[i];
            NBT[i]=BT[i];
        }
        TotalBT=TotalBT+n1-1;
        for(int i=0;i<n1;i++){
            printf("process %s arrivalTime %d BurstTime %d \n ",Pname[i],AT[i],NBT[i]);
        }

        //now main codes for case 2
        for(int i=0;i<TotalBT+12;i++){
        timer=i;
        
        ActivateTheProcess(i);
        Proceeds();
       
    }


    }else{printf("nothing");}


    //this is common for both 

    for(int i=0;i<N;i++){
         
         turnar=turnar+ET[i]-AT[i];
         turnAround[i]=ET[i]-AT[i];
        

     }
     
    printf("Average tournaround time is %f \n",turnar/N);
    averageWaitingTime();
    
}


//all for the case2 implementing
// ###############################################################################################################
//#################################################################################################################




//now keep track to the process which have to process as time proceeds



//this will see wheter process has been finished or in executing state



   
    



#include<stdio.h>
void main()
{
    int numberOfProcess;
    printf("Enter process:");
    scanf("%d",&numberOfProcess);

    int burstTime[numberOfProcess]; //burst time
    int ta[numberOfProcess]; //turn around
    int wt[numberOfProcess]; //wating time

    int totalBurstTime = 0; //for assign turn around time
    float watingTime = 0; // waiting time
    float turnAroundTime = 0; // total of turn around time
    for(int i = 0; i<numberOfProcess;i++)
    {
        int id = i+1;
        printf("Enter burst time for Process %d:",id);
        scanf("%d",&burstTime[i]);
        totalBurstTime += burstTime[i];
        ta[i] = totalBurstTime - 0; //storing turn around time
        wt[i] = totalBurstTime-burstTime[i]; // storing waiting time
        watingTime += wt[i]; //total waiting time
        turnAroundTime += ta[i];
    }


    //table
    printf("\n\n---------------------------\n");
    printf("P.Id\tB.T\tT.A\tW.T\n");
    printf("---------------------------");

    for(int i = 0; i<numberOfProcess; i++)
    {
         int id = i+1;
         if(i == 0)
            printf("\n");
         printf("%d\t%d\t%d\t%d\n",id,burstTime[i],ta[i],wt[i]);
    }

     float avgTaTime = turnAroundTime/numberOfProcess;
     float avgWt = watingTime/numberOfProcess;
     printf("\n\n----------------------------------\n");
     printf("Average of turn around time:%.2f\n",avgTaTime);
     printf("Average of waiting time:%.2f\n",avgWt);
     printf("----------------------------------");


     printf("\n\n-----------------------------------------------------------------\n");
		for(int i = 0; i<numberOfProcess; i++)
		{
			printf("|\tP%d\t",i+1);
			if(i+1 == numberOfProcess)
                printf("|");

		}
     printf("\n-----------------------------------------------------------------\n");

		for(int i = 0;i<numberOfProcess;i++)
		{
			if(i == 0)
			{
				printf("%d\t  \t%d",0,ta[i]);
			}else {
				printf("\t  \t%d",ta[i]);
			}
		}
    getch();
}

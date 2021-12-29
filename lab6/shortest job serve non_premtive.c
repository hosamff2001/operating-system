#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j,time,pos, temp, *bt, *wt, *tat, *p,*ari;
	float avgwt = 0, avgtat = 0;
	printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
    ari = (int*)malloc(n*sizeof(int));
 	
 	printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        printf(" arrive time for P%d : ", i);
        scanf("%d", &ari[i]);
        p[i] = i;
    }
    wt[0] = 0;
    tat[0] = bt[0];
     avgwt += wt[0];
        avgtat += tat[0]; 
        time=bt[0];
        back:
for(i=1; i<n ; i++)
    {
      if(time>ari[i]&&p[i]!=0)
      {
       pos=i;
       }
       for(j=1;j<n;j++)
       {
         if(time>ari[j]&&bt[j]<bt[pos]&&p[j]!=0)
         {
           pos=j;
         }
       }
       
       if(pos!=0)
       {
        wt[pos]=time-ari[pos];
        tat[pos]=wt[pos]+bt[pos];
       time+=bt[pos];
       p[pos]=0;
       
       avgwt += wt[pos];
        avgtat += tat[pos]; 
        pos=0;
      }
      
    }
    
    for(i=1; i<n ; i++)
    {
    if(p[i]!=0)
    {
    goto back;
    }
    
    }
    
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n PROCESS \t ARRIVE TIME \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n",i+1,ari[i] ,bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("-------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], i+1, tat[i]);
    }
}

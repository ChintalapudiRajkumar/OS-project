#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
int cur[5][5], max_claim[5][5], avail[5];
int allocation[5] = {0,0,0,0,0};
int max[5], running[5], safe=0;
int count = 0,i,j,exec,res,pro,k=1;
 
int main()
{
    printf("\nEnter number of processes: ");
    scanf("%d", &pro);
 
    for (i=0; i<pro; i++)
	{
        running[i] = 1;
	    count++;
    }
	printf("\nEnter no. of resources: ");
	scanf("%d", &res);
    printf("\nEnter claim vector:");
   
    for (i = 0; i < res; i++) 
    { 
	    scanf("%d", &max[i]);
    }
 
    printf("\nEnter allocated resource table:\n");
    for (i = 0; i < pro; i++) 
    {
        for(j = 0; j < res; j++) 
        {
              scanf("%d", &cur[i][j]);
        }
    }
 
    printf("\nEnter maximum claim table:\n");
    for (i = 0; i < pro; i++) 
    {
        for(j = 0; j < res; j++) 
        {
            scanf("%d", &max_claim[i][j]);
        }
    }
 
    printf("\nThe Claim Vector is: ");
    for (i = 0; i < res; i++) 
    {
        printf("\t%d", max[i]);
    }
 
    printf("\nThe Allocated Resource Table:\n");
    for (i = 0; i < pro; i++) 
    {
        for (j = 0; j < res; j++) 
        {
            printf("\t%d", cur[i][j]);
        }
    printf("\n");
    }
 
    printf("\nThe Maximum Claim Table:\n");
    for (i = 0; i < pro; i++) 
    {
        for (j = 0; j < res; j++) 
        {
            printf("\t%d", max_claim[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < pro; i++) 
    {
        for (j = 0; j < res; j++) 
        {
            allocation[j] += cur[i][j];
        }
    }
 
    printf("\nAllocated resources:");
    for (i = 0; i < res; i++) 
    {
        printf("\t%d", allocation[i]);
    }
 
    for (i = 0; i < res; i++) 
    {
        avail[i] = max[i] - allocation[i];
    }
 
    printf("\nAvailable resources:");
    for (i = 0; i < res; i++) 
    {
        printf("\t%d", avail[i]);
    }
    printf("\n");
 
    while (count != 0) 
    {
        safe = 0;
        for (i = 0; i < pro; i++) 
        {
            if (running[i]) 
            {
                exec = 1;
                for (j = 0; j < res; j++) 
                {
                    if (max_claim[i][j] - cur[i][j] > avail[j]) 
                    {
                        exec = 0;
                        break;
                    }
                }
                if (exec) 
                {
                    printf("\nProcess%d is executing\n", i+1);
                    running[i] = 0;
                    count--;
                    safe = 1;
					for (j = 0; j < res; j++) 
                    {
                        avail[j] += cur[i][j];
                    }
                    break;
                }
            }
        }
        if (!safe) 
        {
            printf("\nThe processes are in unsafe state.\n");
            break;
        } 
        else 
        {
            printf("\nThe process is in safe state");
            printf("\nAvailable vector:");
 	    	for (i = 0; i < res; i++) 
            {
                printf("\t%d", avail[i]);
            }
		    printf("\n");
        }
    }
    return 0;
}

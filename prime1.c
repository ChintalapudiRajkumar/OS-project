#include<stdio.h>
#include<pthread.h>
void *function1();
int main()
{
	pthread_t thread1;
	pthread_create(&thread1,NULL,function1,NULL);
	pthread_join(thread1,NULL);
}

void *function1()
{
	int n,b,i,m;
	
	printf("Enter the no to print prime nos less or equal to it");
	scanf("%d",&m);
	printf("\n");
	for(b=2;b<=m;b++)
	{
	
 	 i=2;
 	while(b%i!=0)
  	{
  		i++;
  	}
  	
 	if(i==b)
  	{
		printf("%d\n",b) ;
		}
		
  }
 	return 0;
}

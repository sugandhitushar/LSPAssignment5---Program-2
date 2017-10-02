#include"program.h"

#define SHM_SIZE 1024

int main(int argc, char *argv[])
{
	
	int shmid, key=10;	
	char  data[SHM_SIZE],*shMem;
	
	
	shmid = shmget(key, SHM_SIZE, 0666);
	if(shmid == -1)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory accessed and id is: %d\n",shmid);
	
	shMem = shmat(shmid,NULL,0);
	if(shMem == (char *) -1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	
	strcpy(data,shMem);
	printf("Shared data: %s\n",data);
	
	if(shmdt(shMem) == -1)
	{
		perror("shmdt");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}


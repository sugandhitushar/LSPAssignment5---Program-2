#include"program.h"

#define SHM_SIZE 1024

int main(int argc, char *argv[])
{
	
	int shmid, key=10;	
	char  *shMem;
	
	
	shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
	if(shmid == -1)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory created with id: %d\n",shmid);
	
	shMem = shmat(shmid,NULL,0);
	if(shMem == (char *) -1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	
	if(argc==2)
	{
		strcpy(shMem, argv[1]);
	}
	else
	{
		strcpy(shMem,"This is default data");
	}
	
	if(shmdt(shMem) == -1)
	{
		perror("shmdt");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}


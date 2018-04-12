#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t l;

struct trafic
{
int East;
int West;
int North;
int South;
};
void * EW();void * EN();void * ES();void * WE();void * WN();void * WS();void * NE();void * NW();void * NS();void * SE();void * SW();void * SN();
// East direction

void * EW()
{
	EN();     
	NW();
}
void * EN()
{
	pthread_mutex_lock(&l);
	printf("\nYou Are In North\n");
	pthread_mutex_unlock(&l);
}
void * ES()
{
	pthread_mutex_lock(&l);
	printf("\nYou Are In South\n");
	pthread_mutex_unlock(&l);
}

// West direction

void * WE()
{
	WS();
	SE();
}
void *WN()
{
	pthread_mutex_lock(&l);
	printf("\nYou Are In North\n");
	pthread_mutex_unlock(&l);
}
void *WS()
{
	pthread_mutex_lock(&l);
	printf("\nYou Are In South\n");
	pthread_mutex_unlock(&l);
}

// North direction

void *NE()   //For North - East Direction
{
	pthread_mutex_lock(&l);
	printf("\nYou Are In East\n");
	pthread_mutex_unlock(&l);
}
void *NW()   //For North - West Direction
{
	pthread_mutex_lock(&l);
	printf("\nYou Are In West\n");
	pthread_mutex_unlock(&l);
}
void *NS()   //For North - South Direction
{
	NE(); 
	ES();
}

// South direction

void *SE()   //For South - East Direction
{
	pthread_mutex_lock(&l);
	
	printf("\nYou Are In South\n");
	pthread_mutex_unlock(&l);
}

void *SW()
{
	pthread_mutex_lock(&l);
	
	printf("\nYou Are In West(South To West)\n");
	pthread_mutex_unlock(&l);
}

void *SN()
{
	SW();
	WN();
}

main()
{
	pthread_mutex_init(&l, 0);
	pthread_t t1, t2, t3, t4;
	struct trafic * p;
	p->East = 0, p->West = 1, p->North = 2, p->South = 3; 
	int Source = rand()%4, Dest = rand()%4, choice, c;
	printf("\nYour Random Source Is %d\n", Source);
	printf("\nYour Random Destination Is %d\n", Dest);
	choice = Source;
	switch(choice)
	{        
	case 0:
		if(Source == p->East && Dest == p->West){        //E-W   2 fun
			pthread_create(&t1, NULL, EW, NULL);
			pthread_join(t1, NULL);
		}
		else if(Source == p->East && Dest == p->North){  //E-N
			pthread_create(&t1, NULL, EN, NULL);
			pthread_join(t1, NULL);}
		else if(Source == p->East && Dest == p->South){  //E-S
			pthread_create(&t1, NULL, ES, NULL);
			pthread_join(t1, NULL);}
		break;
		
	case 1:
		if(Source == p->West && Dest == p->North) {     //W-N
			pthread_create(&t2, NULL, WN, NULL);
			pthread_join(t2, NULL);}
		else if(Source == p->West && Dest == p->South) { //W-S
			pthread_create(&t2, NULL, WS, NULL);
			pthread_join(t2, NULL);}
		else if(Source == p->West && Dest == p->East) {  //W-E  2 fun
			pthread_create(&t2, NULL, WE, NULL);
			pthread_join(t2, NULL);}
		break;
	case 2:	
		if(Source == p->North && Dest == p->East){  //N-E
			pthread_create(&t3, NULL, NE, NULL);
			pthread_join(t3, NULL);}
		else if(Source == p->North && Dest == p->South){ //N-S  2 fun
			pthread_create(&t3, NULL, NS, NULL);
			pthread_join(t3, NULL);}
		else if(Source == p->North && Dest == p->West){  //N-W
			pthread_create(&t3, NULL, NW, NULL);
			pthread_join(t3, NULL);}
		break;
	case 3:
		if(Source == p->South && Dest == p->West) { //S-W
			pthread_create(&t4, NULL, SW, NULL);
			pthread_join(t4, NULL);}
		else if(Source == p->South && Dest == p->East){  //S-E
			pthread_create(&t4, NULL, SE, NULL);
			pthread_join(t4, NULL);}
		else if(Source == p->South && Dest == p->North){  //S-N  2 fun
			pthread_create(&t4, NULL, SN, NULL);
			pthread_join(t4, NULL);}
		break;
	case 4:
		exit(0);
	default:
		printf("\nPlease choose a valid choice\n");
	}
	
}

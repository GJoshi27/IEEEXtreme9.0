/* =====================================================================================
 *
 *       Filename:  predictiongame.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 24 October 2015 06:57:09  IST
 *       Compiler:  gcc
 *
 *         Author:  Gaurav Joshi , contactgaurav27@gmail.com
 *   Organization:  
 *
 * =====================================================================================*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*===  FUNCTION  ======================================================================
 *  Name:  main
 *  Description:  
 *=====================================================================================*/

#define MAX 1000

typedef struct PlayerScore
{

				char name[100];
				int scP[MAX][2];
				int max;
}PlayerSc;
void display(PlayerSc *data,int p,int c);
void PWinnerUnk(PlayerSc *data,int p,int c,int unk,int *arr);
static int cmpstringp(const void *p1, const void *p2);
void printWinners(PlayerSc *data,int p,int c, int max,int val);

int main ( int argc, char *argv[] )
{

				int T;
				scanf("%d",&T);


				while(T-- > 0)
				{
								int p,c;
								scanf("%d %d",&p,&c);
								int i=0;
								int j=0;
								PlayerSc PS[p]; //Declaring array of structure of p palyers 
								while(i<p)
								{
												PS[i].max=0;
												scanf("%s",PS[i].name);
												j=0;
												for(j=0;j<c;j++)
																scanf("%d %d",&PS[i].scP[j][0],&PS[i].scP[j][1]);
												i++;  

								}

//								display(PS,p,c);
								int unknown=-1;
								for(j=0;j<c;j++){
												char str1[10];
												char str2[10];
												scanf("%s %s",str1,str2);
												int ret=calMax(PS,p,c,str1,str2,j);
												if(ret!=-1)
																unknown=ret;

								}

				//				display(PS,p,c);
								int arrW[p];
								int val=CalcWinners(PS,p,c);

								if(unknown!=-1)
								{
												PWinnerUnk(PS,p,c,unknown,arrW);
												i=0;
												int cnt=0;
												for(i=1;i<p;i++)
												{
																if(arrW[i-1]==arrW[i])
																				cnt++;
																else
																				break;

												}
												if(cnt==p-1)
												{
									              printWinners(PS,p,c,val,15);
												}
												else
												{

									              printWinners(PS,p,c,val,10);
												}

								}
								else
								{
									 //printf("val: %d \n",val);
									 printWinners(PS,p,c,val,0);
								}

				}
				return EXIT_SUCCESS;
}

void display(PlayerSc *data,int p,int c)
{

	int i=0,j=0;

	for(i=0;i<p;i++)
	{
//		printf("%s\n",data[i].name);
		for(j=0;j<c;j++)
			printf("%d %d,Max:%d \n",data[i].scP[j][0],data[i].scP[j][1],data[i].max);
	}

	return;

}

int calMax(PlayerSc *data,int p,int c,char *str1,char *str2,int idx)
{

				if(strcmp(str1,"?")==0)
								return idx;

				//printf("Ccal exisitng max \n");
				int S1=0,S2=0;
				S1=atoi(str1);
				S2=atoi(str2);
				int winner=2;
				if(S1>S2)
								winner=1;
				int i=0,j=0;
				int winnerP=1;
				int P1=0;
				int P2=0;
				for(i=0;i<p;i++)
				{
								winnerP=2;
								P1=data[i].scP[idx][0];
								P2=data[i].scP[idx][1];
								if(P1 > P2)
												winnerP=1;
								if(winner==winnerP)
												data[i].max=data[i].max + 10;

								P1=data[i].scP[idx][0];
								P2=data[i].scP[idx][1];
								data[i].max=data[i].max + Max(0, 5 - abs(S1 - P1));
								data[i].max=data[i].max + Max(0, 5 - abs(S2 - P2));
								data[i].max=data[i].max + Max(0, 5 - abs((P1-P2)-(S1-S2)));


				}
				return -1;

}

int Max(int a,int b)
{
				return (a > b ? a:b);
}

void PWinnerUnk(PlayerSc *data,int p,int c,int unk,int *arr)
{
				int i=0;
				int winner=2;
				int P1,P2;
				for(i=0;i<p;i++)
								*(arr+i)=2;
				for(i=0;i<p;i++)
				{
								P1=data[i].scP[unk][0];
								P2=data[i].scP[unk][1];
								if(P1 > P2)
												*(arr+i)=1;
				}

}

int CalcWinners(PlayerSc *data,int p,int c)
{
				int maxval=0,i=0;
				for(i=0;i<p;i++)
				{
								if(maxval<data[i].max){
												maxval=data[i].max;
								}
				}

				return maxval;

}

void printWinners(PlayerSc *data,int p,int c, int max,int val)
{

				int cnt=0,i=0;
				char *str[p];
				for(i=0;i<p;i++)
				{
								if(max==data[i].max){
												str[cnt]=data[i].name;
//												printf("%s \n",str[0]);
												cnt++;
								}

				}
				if(cnt==1)
								printf("%s\n",str[0]);
				else
				{
								qsort(&str[0],cnt, sizeof(char *), cmpstringp);
//				printf("in qsort\n");
								for(i=0;i<cnt;i++)
												printf("%s ",str[i]);
								printf("\n");
				}



				return ;
}


static int cmpstringp(const void *p1, const void *p2)
{
/*  The actual arguments to this function are "pointers to
		pointers to char", but strcmp(3) arguments are "pointers
		to char", hence the following cast plus dereference */

return strcmp(* (char * const *) p1, * (char * const *) p2);
}

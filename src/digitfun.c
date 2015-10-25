 /* =====================================================================================
 *
 *       Filename:  digitfun.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 24 October 2015 05:53:54  IST
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

#define MAX 1000002
int check(char *);
long long int length(long long int );
int arr[10];

int main ( int argc, char *argv[] )
{
	char str[MAX];
	int i=0;
	arr[0]=2;
	arr[1]=1;
	for(i=2;i<10;i++)
	arr[i]=2;
	scanf("%s",str);

	while(strcmp(str,"END"))
	{
	  int val=0;
		val=check(str);
		printf("%d\n",val);
		memset(str,0,MAX);
		scanf("%s",str);
	}
	return EXIT_SUCCESS;
}

int check(char *str)
{
   int l=strlen(str);
   if(l==1)
	 {
	 int val=atoi(str);
   return arr[val];
	 }
   else
   {
	 char str[l+1];
	 sprintf(str,"%d",l);
   return (check(str)+1);
   }
}

/* ----------  end of function main  ---------- */


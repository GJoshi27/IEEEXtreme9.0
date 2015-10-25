 /* =====================================================================================
 *
 *       Filename:  tacostand.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 24 October 2015 03:00:10  IST
 *       Compiler:  gcc
 *
 *         Author:  Gaurav Joshi , contactgaurav27@gmail.com
 *   Organization:  
 *
 * =====================================================================================*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
long minimum(long a,long b);

/*===  FUNCTION  ======================================================================
 *  Name:  main
 *  Description:  
 *=====================================================================================*/

int main (void )
{
				int N;
				scanf("%d",&N);
				while(N-- > 0)
				{
								long int arr[4];
								scanf("%ld %ld %ld %ld",&arr[0],&arr[1],&arr[2],&arr[3]);
								long int  min=arr[0];
								int idx=0;
								int i=0;
								//printf("minimum among all : %ld \n",min);
								for(i=1;i<4;i++)
								{
												if(min>=arr[i])
												{
																min=arr[i];
																idx=i;
												}
								}
								if(idx==0)
												printf("%ld \n",arr[0]);
								else
								{
												long int maxB=arr[1];
												int idxM=1;
												for(i=2;i<4;i++)
												{
																if(arr[i]>=maxB)
																{
																				idxM=i;
																				maxB=arr[i];
																}
												}
												long int total=0;
												total=total+min;
												arr[0]=arr[0]-min;
												arr[idx]=arr[idx]-min;
												arr[idxM]=arr[idxM]-min;
												if(arr[0]==0)
																printf("%ld \n",total);
												else
												{
																long int minArr[3];
																int k=0;
																int cnt=0;
																for(i=0;i<4;i++)
																{
																				if(arr[i]!=0)
																				{
																								minArr[k]=i;
																								k++;
																				}
																				else
																								cnt++;
																}
																if(cnt>=2)
																				printf("%ld\n",total);
																else
																{
																				long int tmp=minimum(arr[minArr[0]],arr[minArr[1]]);
																				min=minimum(arr[minArr[2]],tmp);
																				total=total+min;
																				printf("%ld\n",total);

																}

												}
								}


				}
				printf("\n");

				return EXIT_SUCCESS;
}

long minimum(long a,long b)
{
return ( a < b ? a:b ) ;

}
/* ----------  end of function main  ---------- */

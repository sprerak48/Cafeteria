#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int rand_cust,c=0,i,k,cust_array[50],n,n1,n2,n3;
//int free[25];
/*typedef struct TABLES
{
int t1[10]; // 2 people
int t2[10]; // 4 people
int t3[5]; //  6 people
};*/
time_t curr_time;
struct tm *time_info,*min;
char timestr[9];



typedef struct Tables
{
  char tab_size;
  char tab_id;
}t[25];

enum Bool{
false,
true
};

struct book
{
  char tab_id;
  char cust_id;
  enum Bool b=false;
  time(&curr_time);
  time_info;
}alloc[25];

typedef struct customer
{
	char cust_id;
	char cust_capacity;
}customer[100];

/*long random_cust()
{
	for(i=1;i<=10;i++)
	{
		rand_cust = rand() % 10;
		if(rand_cust==0)
			continue;
		cust_array[i]=rand_cust;
		printf("\n%d",rand_cust);
		delay(5000);
	}
	return 0;
} */
void tables()
{
	printf("\n Enter no of tables");
	scanf("%d",&n);
	printf("\n Enter no of tables for 2");
	scanf("%d",&n1);
	printf("\n available=%d",n-n1);
	printf("\n Enter no of tables for 4");
	scanf("%d",&n2);
	n3=n-(n1+n2);
	printf("\n tables for 6=%d",n3);
	for(i=0;i<n1;i++)
	{       t[i].tab_id=i+1;
		printf("\nEnter size of table");
		scanf("%d",t[i].tab_size);
	}
	for(i=n1;i<n2;i++)
	{       t[i].tab_id=n1+i;
		printf("\nEnter size of table");
		scanf("%d",t[i].tab_size);
	}
	for(i=n2;i<n3;i++)
	{       t[i].tab_id=n2+i;
		printf("\nEnter size of table");
		scanf("%d",t[i].tab_size);
	}
}
void booking(customer[c].cust_id,customer[c].cust_capacity)
{
     switch(customer[c].cust_capacity)
     {
		case 2:
			for(k=0;k<n1;k++)
			{
				if(alloc[k].b==false)
				{
					alloc[k].tab_id=k+1;
					alloc[k].cust_id=customer[c].cust_id;
					alloc[k].b=true;
					alloc[k].time_info=localtime(&curr_time);
					customer[c].cust_id=NULL;
					customer[c].cust_capacity=NULL;
					break;
				}
			}
			break;
		case 4:
			for(k=n1;k<n2;k++)
			{
				if(alloc[k].b==false)
				{
					alloc[k].tab_id=k+1;
					alloc[k].cust_id=customer[c].cust_id;
					alloc[k].b=true;
					alloc[k].time_info=localtime(&curr_time);
					customer[c].cust_id=NULL;					break;
					customer[c].cust_capacity=NULL;
					break;
				}
			}
			break;
		case 6:
		       for(k=n2;k<n3;k++)
			{
				if(alloc[k].b==false)
				{
					alloc[k].tab_id=k+1;
					alloc[k].cust_id=customer[c].cust_id;
					alloc[k].b=true;
					alloc[k].time_info=localtime(&curr_time);
					customer[c].cust_id=NULL;
					customer[c].cust_capacity=NULL;
					break;
				}
			}
			break;
		default:
			printf("\n Enter between 2 4 6");
     }
}
char check_free()    //to make table free after some time
{       min=alloc[0].time_info;
	for(k=1;k<n;k++)
	{	if(alloc[k].b==true)
		{
			if(min>(a[k].time_info))
			{	min=a[k].time_info;
				loc=k;
			 }
		}
	}
	alloc[loc].cust_id=NULL;
	alloc[loc].b=true;
}
/*
void free_table()
{
	if(alloc[k].b==true)
	{
	      //	alloc[k].tab_id=k+1;
		alloc[k].cust_id=NULL;
		alloc[k].b=false;
		break;
       }
}
*/
void main()
{
	clrscr();
	tables();
	if(c==99) //assume max 100 cust in an array
	{c=0;
	}
	printf("ENTER CUSTOMER ID AND NO OF PEOPLE");
	scanf("%s %s ",&customer[c].cust_id,&customer[c].cust_capacity);
	c++;
		//random_cust();
       //	for(i=1;i<=10;i++)
	 //	printf("\n%d",cust_array[i]);
	getch();
}

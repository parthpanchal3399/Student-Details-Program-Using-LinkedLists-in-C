/*Program For Student Details Using Linked Lists*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct node{
	int roll,tt1,tt2,div;
	char fname[20],lname[20],cl[5];
	float avg;
	struct node *right,*left;
};

/*Declarations*/
void insert_beg();
struct node *search(int r);
void swap(struct node *p,struct node *q);
void sort();
void update_fname(struct node *res);
void update_lname(struct node *res);
void update_tt1(struct node *res);
void update_tt2(struct node *res);
void update();
void display();
void delete_rec();

struct node *start = NULL;

void insert_beg()
{
	system("cls");
	int r;
	struct node *nn,*res;
	printf("Enter Roll Number: ");
	scanf("%d",&r);
	if(start!=NULL)
		res = search(r);
	if(res==NULL || start == NULL)
	{
		nn = (struct node *)malloc(sizeof(struct node));
		nn->right = nn->left = NULL;
	
		nn->roll = r;
		printf("\n");
		printf("Enter First Name: ");
		scanf("%s",nn->fname);
		printf("\n");
		printf("Enter Last Name: ");
		scanf("%s",nn->lname);
		printf("\n");
		printf("Enter Class: ");
		scanf("%s",nn->cl);
		printf("\n");
		printf("Enter Division: ");
		scanf("%d",&nn->div);
		printf("\n");
		printf("Enter Term Test 1 Marks: ");
		scanf("%d",&nn->tt1);
		printf("\n");
		printf("Enter Term Test 2 Marks: ");
		scanf("%d",&nn->tt2);
		printf("\n");
		nn->avg = (float)(nn->tt1 + nn->tt2)/2;	
		
		if(start == NULL)
			start = nn;
		else
		{
			nn->right = start;
			start->left = nn;
			start = nn;
		}
		sort();
	}
	
	else
	{
		printf("Duplicate Roll Number!!\n\n");
	}
}

void swap(struct node *p,struct node *q)
{
	int temproll,tempdiv,tempt1,tempt2;
	float tempavg;
	char tempfname[20],templname[20],tempcl[5];
	temproll = p->roll;
	p->roll = q->roll;
	q->roll = temproll;
	
	strcpy(tempfname,p->fname);
	strcpy(p->fname,q->fname);
	strcpy(q->fname,tempfname);
	
	strcpy(templname,p->lname);
	strcpy(p->lname,q->lname);
	strcpy(q->lname,templname);
	
	strcpy(tempcl,p->cl);
	strcpy(p->cl,q->cl);
	strcpy(q->cl,tempcl);
	
	tempdiv = p->div;
	p->div = q->div;
	q->div = tempdiv;
	
	tempt1 = p->tt1;
	p->tt1 = q->tt1;
	q->tt1 = tempt1;
	
	tempt2 = p->tt2;
	p->tt2 = q->tt2;
	q->tt2 = tempt2;
	
	tempavg = p->avg;
	p->avg = q->avg;
	q->avg = tempavg;
	
}

void sort()
{
	int swapped,i;
	struct node *p;
	struct node *q=NULL;
	if (start == NULL)
		printf("No records..!");
	
	do
	{
		swapped = 0;
		p = start;
		
		while(p->right!=q)
		{
			if(p->roll > p->right->roll)
			{
				swap(p,p->right);
				swapped = 1;
			}
			p = p->right;
			
		}
		q = p;
	}while(swapped);
}

void update_fname(struct node *res)
{
	system("cls");
	printf("Enter Updated First Name: ");
	scanf("%s",res->fname);
}

void update_lname(struct node *res)
{
	system("cls");
	printf("Enter Updated Last Name: ");
	scanf("%s",res->lname);
}

void update_tt1(struct node *res)
{
	system("cls");
	printf("Enter Updated Term Test 1 Marks: ");
	scanf("%d",&res->tt1);
	res->avg = (float)(res->tt1 + res->tt2)/2;	
}

void update_tt2(struct node *res)
{
	system("cls");
	printf("Enter Updated Term Test 2 Marks: ");
	scanf("%d",&res->tt2);
	res->avg = (float)(res->tt1 + res->tt2)/2;
}

struct node *search(int r)
{
	struct node *p;
	if(start == NULL)
		printf("No records..123!\n");
	else
	{
		p = start;
		while(p!=NULL)
		{
			if(p->roll==r)
				return p;
			else
				p = p->right;
		}
	}
}

void update()
{
	system("cls");
	struct node *res;
	int m2,roll;
	printf("Enter Roll Number Whose Details You want to update: ");
	scanf("%d",&roll);
	res = search(roll);
	if(res==NULL)
		printf("No Record Found!\n");
	else
	{
		do
		{
			system("cls");
			printf("Select:");
			printf("\n\n");
			printf("1.Update First Name");
			printf("\n");
			printf("2.Update Last Name");
			printf("\n");
			printf("3.Update Term Test 1 Marks");
			printf("\n");
			printf("4.Update Term Test 2 Marks");
			printf("\n");
			printf("0.Back");
			printf("\n");
			scanf("%d",&m2);
			switch(m2)
			{
				case 0: break;
				case 1: update_fname(res);
						break;
				case 2: update_lname(res);
						break;
				case 3: update_tt1(res);
						break;
				case 4: update_tt2(res);
						break;
					default: printf("INVAILD CHOICE");
			}
		
		}while(m2!=0);
	}
	system("cls");
}

void display()
{
	system("cls");
	struct node *p;
	if(start == NULL)
		printf("No Record!...");
	else
	{
		printf("________________________________________________________________________________________________________");
		printf("\n");
		printf("RollNo\tFirstName\t\tLastName\t\tClass\tDivision\tTT1\tTT2\tAverage");
		printf("\n");
		printf("________________________________________________________________________________________________________");
		printf("\n");
		p = start;
		while(p!=NULL)
		{
			printf("%d\t",p->roll);
			printf("%s\t\t\t",p->fname);
			printf("%s\t\t\t",p->lname);
			printf("%s\t",p->cl);
			printf("%d\t\t",p->div);
			printf("%d\t",p->tt1);
			printf("%d\t",p->tt2);
			printf("%5.2f\t",p->avg);
			printf("\n");
			p = p->right;
		}
		
	}
	system("pause");
	system("cls");
}

void delete_rec()
{
	system("cls");
	int r;
	struct node *res;
	printf("Enter Roll Number Who's record you want to delete: ");
	scanf("%d",&r);
	if(start->roll == r)
	{
		res = start;
		start = start->right;
		free(res);
	}
	else
	{
		res = search(r);
		res->left->right = res->right;
		res->right->left = res->left;
		free(res);
	}
	printf("Record of Roll No. %d Deleted Successfully!\n",r);
}

int main()
{
	system("cls");
	int m1;
	do
	{
		printf("*********************STUDENT DETAILS*********************");
		printf("\n\n");
		printf("1.Add Details");
		printf("\n");
		printf("2.Update Details");
		printf("\n");
		printf("3.Display Record");
		printf("\n");
		printf("4.Delete Record");
		printf("\n");
		printf("0.Exit");
		printf("\n");
		scanf("%d",&m1);
		switch(m1)
		{
			case 0:	break;
			case 1: insert_beg();
					break;
			case 2: update();
					break;
			case 3: display();
					break;
			case 4: delete_rec();
					break;
		}	
	}while(m1!=0);
	return 0;
}


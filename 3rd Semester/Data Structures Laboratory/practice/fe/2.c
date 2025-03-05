#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct employee{
	char name[MAX];
	int id;
	char dept[MAX];
	float sal;
} E;

void dept_sal(int n, E *emp_array,const char *dept_name){
	float total=0;
	for(int i=0;i<n;i++){
		if(strcmp(emp_array[i].dept,dept_name)==0){
			total+=emp_array[i].sal;
		}
	}
	printf("The total sal of dept %s is %.2f",dept_name,total);
}

int main(){
	int n;
	char dept_name[MAX];
	printf("Enter no of employees: ");
	scanf("%d",&n);
	
	E *emp_array = malloc(n*sizeof(E));

	for(int i=0;i<n;i++){
	printf("Enter Employee %d name,id,dept,salary",i+1);
	scanf("%s%d%s%f",emp_array[i].name,&emp_array[i].id,emp_array[i].dept,&emp_array[i].sal);
	}

	for(int i=0;i<n;i++){
		printf("Employee details: ");
		printf("Employee %d: name: %s, id:%d, dept:%s, salary:%f",i+1,emp_array[i].name,emp_array[i].id,emp_array[i].dept,emp_array[i].sal);
	}

	printf("Enter dept to get total salary: ");
	scanf("%s",dept_name);

	dept_sal(n,emp_array,dept_name);
	free(emp_array);
	return 0;
}


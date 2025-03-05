// Program 2 Employee Structure
//  Define an EMPLOYEE structure with members Emp_name, Emp-id, Dept-name and Salary.
//  Read and display data of N employees. Employees may belong to different departments.
//  Write a function to find the total salary of employees of a specified department. Use the
//  concept of pointer to structure and allocate the memory dynamically to EMPLOYEE
//  instances.

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

float dept_sal(E *emp_array,int n,const char *dept_name){
    float total=0;
    for(int i=0;i<n;i++){
        if(strcmp(emp_array[i].dept,dept_name)==0){
        total+=emp_array[i].sal;
        }
    }
    return total;
}

void display(E *emp_array,int n){
    for(int i=0;i<n;i++){
        printf("Employee %d:%s,ID:%d,Dept:%s,Salary:%.2f\n",i+1,emp_array[i].name,emp_array[i].id,emp_array[i].dept,emp_array[i].sal);
    }
}

int main(){
    int n;
    char dept_name[MAX];
    printf("ENter no of employeees: ");
    scanf("%d",&n);

    E *emp_array = malloc(n*sizeof(E));

    for(int i=0;i<n;i++){
        printf("Enter name,id,dept,sal of employee %d: ",i+1);
        scanf("%s %d %s %f",emp_array[i].name,&emp_array[i].id,emp_array[i].dept,&emp_array[i].sal);
    }

    printf("Employee Details: ");
    display(emp_array,n);

    printf("Enter dept for total salary: ");
    scanf("%s",dept_name);
    printf("The total sal in %s : %.2f\n",dept_name,
    dept_sal(emp_array,n,dept_name));
    free(emp_array);
    return 0;
}
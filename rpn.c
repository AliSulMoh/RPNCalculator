/*
 * main_queue.c
 */

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

int find_gcd(int a, int b) {
	if (b == 0){
	return a;}
	return find_gcd(b, a % b);
}

void print_top(stack * n, stack * d){
if (get_name(n) != NULL){
printf("%d/%d\n",*get_name(n),*get_name(d));
}}



int main ()
{
  char input[MAX_LINE_LENGTH];
  char command[MAX_LINE_LENGTH];
  int sample = 5;
  int *name = &sample;
  int* num1 = NULL;
  int* num2 = NULL;
  int* denom1 = NULL;
  int* denom2 = NULL;
  int gcd;
  int numAns;
  int denomAns;
  int exit = 1;
  stack num;
  stack denom;

  init_stack(&num);
	init_stack(&denom);
  //printf("%d\n",*name);
  while (exit) {
  num1=NULL;
    num2=NULL;
    denom1=NULL;
    denom2=NULL;
    //printf ("Enter command (add, delete, list quit) : \n");

    fgets (input, MAX_LINE_LENGTH, stdin);

  
    // Check for add command
    if (sscanf (input, "%d", name)==1){
      
    //  printf("%d\n",*name);
      
      add_name (&num, name);
      //printf("b\n");
      
      *name = 1;
      add_name (&denom, name);
      print_top(&num, &denom);
      }
    else {
    	sscanf (input, "%s", command);
    	for(int i = 0; command[i]; i++){
  			command[i] = tolower(command[i]);
			}
    	if (strcmp(command, "+")==0){
    		num1 = remove_name(&num);
    		num2 = remove_name(&num);
    		denom1 = remove_name(&denom);
    		denom2 = remove_name(&denom);
    		if (num1 == NULL) {
    		printf("STACK ERROR\n");
    		continue;
    		} else if (num2==NULL){
    		add_name(&num, num1);
    		add_name(&denom, denom1);
    		free(num1);free(denom1);
    		printf("STACK ERROR\n");
    		continue;
    		}
    		numAns = *num1*(*denom2) + *num2*(*denom1);
    		denomAns = *denom1**denom2;
    		gcd = find_gcd(denomAns, numAns);
    		numAns = numAns / gcd;
    		denomAns = denomAns / gcd;
    		if (denomAns < 0) {
denomAns = denomAns * -1;
numAns = numAns * -1;
}

    		*name = numAns;
    		add_name(&num, name);
    		*name = denomAns;
    		add_name(&denom, name);
    		print_top(&num, &denom);
    		
    	}else if (strcmp(command, "-")==0){
    	num1 = remove_name(&num);
    		num2 = remove_name(&num);
    		denom1 = remove_name(&denom);
    		denom2 = remove_name(&denom);
    		if (num1 == NULL) {
    		printf("STACK ERROR\n");
    		continue;
    		} else if (num2==NULL){
    		add_name(&num, num1);
    		add_name(&denom, denom1);
    		printf("STACK ERROR\n");
    		free(num1);free(denom1);
    		continue;
    		}
    		numAns = *num2**denom1 - *num1**denom2;
    		denomAns = *denom1**denom2;
    		gcd = find_gcd(denomAns, numAns);
    		numAns = numAns / gcd;
    		denomAns = denomAns / gcd;
    		if (denomAns < 0) {
denomAns = denomAns * -1;
numAns = numAns * -1;
}

    		*name = numAns;
    		add_name(&num, name);
    		*name = denomAns;
    		add_name(&denom, name);
    		print_top(&num, &denom);
    	}else if (strcmp(command, "*")==0){
    	num1 = remove_name(&num);
    		num2 = remove_name(&num);
    		denom1 = remove_name(&denom);
    		denom2 = remove_name(&denom);
    		if (num1 == NULL) {
    		printf("STACK ERROR\n");
    		continue;
    		} else if (num2==NULL){
    		add_name(&num, num1);
    		add_name(&denom, denom1);
    		printf("STACK ERROR\n");
    		free(num1);free(denom1);
    		continue;
    		}
    		numAns = *num1**num2;
    		denomAns = *denom1**denom2;
    		gcd = find_gcd(denomAns, numAns);
    		numAns = numAns / gcd;
    		denomAns = denomAns / gcd;
    		if (denomAns < 0) {
denomAns = denomAns * -1;
numAns = numAns * -1;
}

    		*name = numAns;
    		add_name(&num, name);
    		*name = denomAns;
    		add_name(&denom, name);
    		print_top(&num, &denom);
    	}else if(strcmp(command, "/")==0){
    	num1 = remove_name(&num);
    		num2 = remove_name(&num);
    		denom1 = remove_name(&denom);
    		denom2 = remove_name(&denom);
    		if (num1 == NULL) {
    		printf("STACK ERROR\n");
    		continue;
    		} else if (num2==NULL){
    		add_name(&num, num1);
    		add_name(&denom, denom1);
    		printf("STACK ERROR\n");
    		free(num1);free(denom1);
    		continue;
    		}
    	numAns = *denom1**num2;
    		denomAns = *denom2**num1;
    		if (denomAns == 0) {
exit = 0;
printf("DIVIDE BY ZERO");
delete_all_entries(&num);
delete_all_entries(&denom);
} else {

    		gcd = find_gcd(denomAns, numAns);
    		numAns = numAns / gcd;
    		denomAns = denomAns / gcd;
    		if (denomAns < 0) {
denomAns = denomAns * -1;
numAns = numAns * -1;
}

    		*name = numAns;
    		add_name(&num, name);
    		*name = denomAns;
    		add_name(&denom, name);
    		print_top(&num, &denom);}
    	}else if(strcmp(command, "dup")==0){
    	num1 = remove_name(&num);
    	denom1 = remove_name(&denom);
    	if (num1 == NULL) {
    		printf("STACK ERROR\n");
    		continue;}
    	*name = *num1;
    		add_name(&num, name);
    		add_name(&num, name);
    		*name = *denom1;
    		add_name(&denom, name);
    		add_name(&denom, name);
    		print_top(&num, &denom);
    	}else if(strcmp(command, "swap")==0){
    	num1 = remove_name(&num);
    		num2 = remove_name(&num);
    		denom1 = remove_name(&denom);
    		denom2 = remove_name(&denom);
    		if (num1 == NULL) {
    		printf("STACK ERROR\n");
    		continue;
    		} else if (num2==NULL){
    		add_name(&num, num1);
    		add_name(&denom, denom1);
    		printf("STACK ERROR\n");
    		free(num1);free(denom1);
    		continue;
    		}
    	*name = *num1;
    		add_name(&num, name);
    		*name = *num2;
    		add_name(&num, name);
    		*name = *denom1;
    		add_name(&denom, name);
    		*name = *denom2;
    		add_name(&denom, name);
    		print_top(&num, &denom);
    	}else if(strcmp(command, "quit")==0){
    	delete_all_entries(&num);
    	delete_all_entries(&denom);
    	
    	exit = 0;
    	}else if(strcmp(command, "drop")==0){
    	num1 = remove_name(&num);
    	denom1 = remove_name(&denom);
    	if (num1 == NULL) {
    		printf("STACK ERROR\n");
    		continue;}
    	print_top(&num, &denom);
    	}else if(strcmp(command, "clear")==0){
    	delete_all_entries(&num);
    	delete_all_entries(&denom);
    	}else{
    	printf("INVALID COMMAND\n");
    	}
    free(num1);
    free(num2);
    free(denom1);
    free(denom2);
    
    //print_stack(&num);
     // print_stack(&denom);
    
    
    
    
    }
    

/*    // Check for delete command
    if (input[0] == 'd') {
      remove_first_name (&theQueue);
      print_queue (&theQueue);
    }

    // Check for list command
    if (input[0] == 'l') {
      print_queue (&theQueue);
    }

    // check for quit command
    if (input[0] == 'q') {
      delete_all_entries (&theQueue);
      exit (0);
    }
    */
  }
  
  return 0;
}

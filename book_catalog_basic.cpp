#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define MAX 100

int menu();
void display(int i), enter(), author_search(), title_search();

char names[MAX][80];
char titles[MAX][80];
char pubs[MAX][80];

int top = 0;

int main(){
	int choice;
	do{
		choice = menu();
		switch(choice){
			case 1: enter(); break;
			case 2: author_search(); break;
			case 3: title_search(); break;
		}
	}while(choice !=4);
}

int menu(){
	int i;
	printf("Card Catalog:\n");
	printf("1. Enter\n");
	printf("2. Search by Author\n");
	printf("3. Search by Title\n");
	printf("4. Quit\n");
	do{
		printf("Choose your selection: ");
		i = getche() - '0';
		printf("\n");
	}while(i<1 || i>4);
	return i;
}

void display(int i) {
	printf("%s\n",titles[i]);
	printf("by %s\n",names[i]);
	printf("Published by %s\n",pubs[i]);
}

void enter() {
	int i;
	for(i=top;i<MAX;i++){
		printf("Enter author name (Enter to quit): ");
		gets(names[i]);
		if(!*names[i]) break;
		printf("Enter title: ");
		gets(titles[i]);
		printf("Enter publisher: ");
		gets(pubs[i]);
	}
	top = i;
}

void author_search(){
	char name[80];
	int i, found;
	
	printf("Name: ");
	gets(name);
	
	found = 0;
	for(i=0;i<top;i++)
	if(!strcmp(name,names[i])){
		display(i);
		found = 1;
		printf("\n");
	}
	if(!found) printf("not found\n");
}

void title_search() {
	char title[80];
	int i, found;
	
	printf("Title: ");
	gets(title);
	
	found = 0;
	for(i=0;i<top;i++)
	if(!strcmp(title,titles[i])){
		display(i);
		found = 1;
		printf("\n");
	}
	if(!found) printf("not found\n");
}

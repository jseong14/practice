#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 100

int menu();
void enter(), find(), save(), load();

char names[MAX][80];
char phones[MAX][80];

int top =0;

int main(){
	int choice;
	do{
		choice = menu();
		switch(choice){
			case 1: enter(); break;
			case 2: find(); break;
			case 3: save(); break;
			case 4: load(); break;
		}
	}while(choice != 5);
	
}

menu(){
	int i;
	printf("1. Enter the names and numbers\n");
	printf("2. Find numbers\n");
	printf("3. Save directory to disk\n");
	printf("4. Load directory from disk\n");
	printf("5. Quit");
	
	do{
		printf("Choose your selection:");
		i = getche()-'0';
		printf("\n");
	}while(i<1 || i>5);
	return i;
}

void enter(){
	for(;top<MAX;){
		if(top<100){
			printf("enter names and phone numbers (Enter to quit):\n");
			printf("Names: ");
			gets(names[top]);
			if(!*names[top]) break;
			printf("Phone: ");
			gets(phones[top]);
			top++;
		}
	}
}

void find(){
	char name[80];
	int i;
	
	printf("찾고자하는 이름은? : ");
	gets(name);
	
	for(i=0;i<MAX;i++)
	if(!strcmp(name,names[i])){
		printf("\n찾았습니다.\n");
		printf("%s %s\n", names[i],phones[i]);
	}
}

void load(){
	FILE *fp;
	if((fp=fopen("phone","r"))==NULL){
		printf("cannot open file");
		exit(1);
	}
	
	top = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s",names[top],phones[top]);
		top++;
	}
	printf("파일에서 읽어 왔어요.\n\n");
	fclose(fp);
}

void save(){
	FILE *fp;
	int i;
	if((fp=fopen("phone","w"))==NULL){
		printf("cannot open file");
		exit(1);
	}
	
	for(i=0;i<top;i++){
		fprintf(fp,"%s %s", names[i],phones[i]);
	}
	printf("파일에 저장 되었습니다.\n\n");
	fclose(fp);
}

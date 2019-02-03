#include<stdio.h>
#include<string.h>
#include<conio.h>
struct node{
    int output1;
    int statenumber1;
    int output2;
    int statenumber2;
    };
    
int main(){
	int state, i, statenumber, length, temp;
	char inputstring[20], newinput;
	printf("\t\tMEALY MACHINE\n\n"); //Mealy Machine for inputs "0" and "1"
	printf("  Enter number of state :-"); //Number of states present in transition diagram
	scanf("%d",&state);
	
 	struct node q[state];
 	
	 printf("\n  Enter Transition table :-\n");
 	
	 for(i=0;i<state;i++){
		
		printf("\n\tState q[%d]\n",i);
	
		printf(" Enter next state number for input 0:- " );  // Enter state number for input 
		scanf("%d", &statenumber);
		q[i].statenumber1=statenumber;
		printf(" Enter output of input 0 :-");
		scanf("%d",&q[i].output1);
		
		printf(" Enter next state number for input 1:-" );// Enter state number for input 
		scanf("%d", &statenumber);
		q[i].statenumber2=statenumber;
		printf(" Enter output of input 1 :-");
		scanf("%d",&q[i].output2);
		
 	}
 		printf("State\tInput 0 \t Input 1 \n");
 
 	for(i=0;i<state;i++){
		printf("q[%d]\tq[%d]\t%d\tq[%d]\t%d\n",i,q[i].statenumber1,q[i].output1,q[i].statenumber2,q[i].output2);
 	}
 	
 	printf("\nEnter Input String:-");  // Enter Input string
	 scanf("%s",&inputstring);
 	
 	length=strlen(inputstring);
    
	statenumber = 0;
	
	printf("\nOutput :- ");
    
	for(i=0;i<length;i++){
		
		if(inputstring[i]=='0'){
			if(state<statenumber){
				printf("\n Wrong State \n Halt");
				break;
			}
			printf("%d", q[statenumber].output1);
			statenumber=q[statenumber].statenumber1;
		}
		else if(inputstring[i]=='1'){
			if(state<statenumber){
				printf("\n HALT");
				break;
			}
			printf("%d",q[statenumber].output2);
			statenumber=q[statenumber].statenumber2;
		}
		else{
			printf("\n HALT");
			break;
		}
		
		
    }
    getch();
}
    


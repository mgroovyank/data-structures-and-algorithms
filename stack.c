#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main(){
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n STACK OPERATIONS USING ARRAY");
    printf("\n-------------------------------");
    printf("\n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT");

    do{
      printf("\nEnter the choice:");
      scanf("%d",&choice);
      switch(choice){
          case 1:{
              push();
              break;
          }
          case 2:{
              pop();
              break;
          }
          case 3:{
              display();
              break;
          }
          case 4:{
              printf("\n EXIT POINT");
              break;
          }
          default:{
              printf("\n PLEASE ENTER A VALID CHOICE");
          }
      }
    }while(choice!=4);
}

void push(){
    if(top>n-1){
        printf("\n STACK IS OVERFLOW");
    }else{
        printf("\n ENTER THE VALUE TO BE PUSHED");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop(){
    if(top<=-1){
        printf("\n THE STACK IS UNDERFLOW");
    }else{
       printf("\n THE POPPED ELEMENT IS %d",stack[top]);
       top--;
    }
}

void display(){
    if(top>=0){
        printf("\n THE ELEMENTS IN STACK ARE:");
        for(i=top;i>=0;i--){
        printf("\n%d",stack[i]);
    }
    }else{
        printf("\n THE STACK IS EMPTY");
    }
}



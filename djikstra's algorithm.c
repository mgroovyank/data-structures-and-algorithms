//Djikstra's algorithm for evaluating arithmetic expressions
//You have to put every pair of values inside parentheses otherwise this would not work.

#include<stdio.h>
#include<stdlib.h>
struct vals
{
  int val;
  struct vals *next;
};
struct ops
{
  char opr;
  struct ops *next;
};
struct vals *head_vals=NULL;
struct ops *head_ops=NULL;
void push_vals(int val);
void push_ops(char data);
int pop_vals();
char pop_ops();
int main()
{
  char exp[]="(1+(5*5*4))";
  int i=0;
  while(exp[i]!='\0'){
    if(exp[i]=='('){
      i++;
    }else if(exp[i]=='+' || exp[i]=='*'){
      push_ops(exp[i]);
      i++;
    }else if(exp[i]==')'){
      int first_val=pop_vals();
      int second_val=pop_vals();
      char opr=pop_ops();
      if(opr=='+'){
        push_vals(first_val+second_val);
      }
      if(opr=='*'){
        push_vals(first_val*second_val);
      }
      i++;
    }else{
      push_vals(exp[i]-'0');//convert char to int
      i++;
    }
  }
  printf("%d",head_vals->val);
}

void push_vals(int val){
  struct vals *newHead=NULL;
  newHead=(struct vals*)malloc(sizeof(struct vals));
  newHead->val=val;
  newHead->next=head_vals;
  head_vals=newHead;
}
void push_ops(char opr){
  struct ops *newHead=NULL;
  newHead=(struct ops*)malloc(sizeof(struct ops));
  newHead->opr=opr;
  newHead->next=head_ops;
  head_ops=newHead;
}

int pop_vals(){
  struct vals *temp=head_vals;
  head_vals=head_vals->next;
  temp->next=NULL;
  int val=temp->val;
  free(temp);
  return val;
}
char pop_ops(){
  struct ops *temp=head_ops;
  head_ops=head_ops->next;
  temp->next=NULL;
  char opr=temp->opr;
  free(temp);
  return opr;
}

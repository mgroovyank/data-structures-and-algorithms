// Linear probing Symbol Table 
//author @mgroovyank(MAYANK CHHIPA)


#include<stdio.h>
char st[16];
int values[16];
void put(char key,int val,int hash);
int get(char key,int hash);

int main(){
  char keys[]={'S','E','A','R','C','H','X','M','P','L'};
  int hash[]={6,10,4,14,5,4,15,1,14,6};
  int i;
  for(i=0;i<16;i++){//initialize array to empty
    st[i]=-1; 
    values[i]=-1;
  }

  put('S',0,6);
  int v=get('S',6);
  printf("%d",v);
}

void put(char key,int val,int hash){
  int i;
  i=hash;
  if(st[i]==-1){
    st[i]=key;
    values[i]=val;
    return;
  }
  for(i=hash;i<16;i++){
    if(st[i]==-1){
      st[i]=key;
      values[i]=val;
      return;
    }
  }
}

int get(char key,int hash){
  int i;
  i=hash;
  if(st[i]==key){
    return values[i];
  }
  for(i=hash;i<16;i++){
    if(st[i]==key){
      return values[i];
    }
  }
  for(i=0;i<hash;i++){
    if(st[i]==key){
      return values[i];
    }
  }
  printf("No such key exists");
  return 0;
}
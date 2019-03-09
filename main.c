//Implement Hash Code for Strings:Horner's Method
//@author mgroovyank(MAYANK CHHIPA)

#include <stdio.h>
int main() {
  char s[]={'c','a','l','l'};
  int i;
  int hash=0;
  for(i=0;i<4;i++){
    hash=s[i]+31*hash;
  }
  printf("%d",hash);
}

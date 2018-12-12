#include <stdio.h>
int main(void) {
  int data[8]={30,-40,-20,-10,40,0,10,5};
  int i,j,k,n=0;
  int data_length=sizeof(data)/sizeof(data[0]);
  for(i=0;i<data_length;i++){
    for(j=i+1;j<data_length;j++){
      for(k=j+1;k<data_length;k++){
        if(data[i]+data[j]+data[k]==0){
          n++;
        }
      }
    }
  }
  printf("THE NUMBER OF THREE SUMS IS %d",n);
}

#include<stdio.h>
#include<unistd.h>
#include<math.h>
int main(){
    int bag[3],i;
    for(i=0;i<3;i++){
        printf("\n ENTER THE VALUE IN THE BAG:");
        scanf("\n %d",&bag[i]);
    }
    int n=sizeof(bag)/sizeof(bag[0]);
    printf("\n %d",n);
    double mean=0,sigma=0;
    for(i=0;i<n;i++){
        mean=mean+bag[i];
    }
    mean=mean/n;
    printf("\n THE MEAN OF VALUES IN BAG IS %lf",mean);
    mean=mean/n;
    for(i=0;i<n;i++){
        sigma=sigma+pow(bag[i]-mean,2);
    }
    sigma=sigma/n-1;
    printf("\n THE STANDARD DEVIATION OF DATA IS %lf",sigma);

    return 0;
}

#include<stdio.h>
int arr[4][4],next[4][4],i,j,x,y,neighbours=0, diagonal=0;direct=0;

int main()
{   //forming 4x4 random matrix
    printf("The random Matrix is:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            arr[i][j]=(rand()%2);
            printf("%d",arr[i][j]);
            if(j==3)
                printf("\n");
        }
    }
    i=0,j=0;
    printf("The next gen matrix is: \n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){

           // Centre Matrix
           diagonal = arr[i-1][j-1]+arr[i-1][j+1]+ arr[i+1][j-1]+ arr[i+1][j+1];  //diagonal neighbours
           direct = arr[i-1][j]+arr[i][j-1]+ arr[i+1][j]+ arr[i][j+1];    //direct neighbours
            neighbours = diagonal+direct;  //total neighbours
            if(arr[i][j]==1 && (neighbours<2||neighbours>3))   // over population or underpopulated
                next[i][j]= 0;
            if(arr[i][j]==1 && (neighbours==2||neighbours==3))  //survival
                next[i][j]= 1;
            if(arr[i][j]==0 && neighbours==3){ //birth
                next[i][j]= 1;
                }
            printf("%d",next[i][j]);
            if(j==3)
                printf("\n");
        }
    }
  arr[i][j]=next[i][j];

}



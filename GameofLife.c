#include<stdio.h>
#include<time.h>
#define row 4
#define column 4

int arr[row][column],next[row][column],i,j,neighbours=0, diagonal=0;direct=0;

int main()
{   //forming row x column random matrix
    printf("The random Matrix is:\n");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            arr[i][j]=(rand()%2);
            printf("%d",arr[i][j]);
            if(j==column-1)
                printf("\n");
        }
    }

    while(1){
    neighbours=0,diagonal=0, direct=0;
    sleep(1);
    printf("The next gen matrix is: \n");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
             if(i==0 && j==0){  //Top left corner
                diagonal = arr[i+1][j+1];
                direct = arr[i][j+1]+arr[i+1][j];
                neighbours = diagonal+direct;
             }
             if(i==0 && (j>0&&j<column-1)){  //top row leaving corners
                diagonal = arr[i+1][j-1]+arr[i+1][j+1];
                direct = arr[i][j-1]+arr[i][j+1]+arr[i+1][j];
                neighbours = diagonal+direct;
             }
             if(i==0 && j==column-1){ //Top right corner
                diagonal = arr[i+1][j-1];
                direct = arr[i][j-1]+arr[i+1][j];
                neighbours = diagonal + direct;
             }
             if((i>0 && i<row-1) && j==0){ //extreme Left Column leaving corners
                diagonal = arr[i-1][j+1]+arr[i+1][j+1];
                direct = arr[i-1][j]+arr[i][j+1]+arr[i+1][j];
                neighbours = diagonal+direct;
             }
             if(i==row-1 && j== 0){ //Bottom left corner
                diagonal = arr[i-1][j+1];
                direct = arr[i-1][j]+arr[i][j+1];
                neighbours = diagonal + direct;
             }
             if(i==row-1&&(j>0&&j<column-1)){ //Bottom row leaving corners
                diagonal = arr[i-1][j-1]+arr[i-1][j+1];
                direct = arr[i][j-1]+arr[i][j+1]+arr[i-1][j];
                neighbours = diagonal + direct;
             }

             if(i==row-1 && j==column-1){ // Bottom Right corner
                diagonal = arr[i-1][j-1];
                direct = arr[i][j-1]+arr[i-1][j];
                neighbours = diagonal + direct;
             }

             if((i>0&&i<row-1)&& j==column-1){  // extreme right column leaving corners
                diagonal = arr[i-1][j-1]+arr[i+1][j-1];
                direct = arr[i-1][j]+arr[i+1][j]+arr[i][j-1];
                neighbours = diagonal + direct;
             }

            if((i>0&&i<row-1) && (j>0&&j<column-1)){// mid
            diagonal = arr[i-1][j-1]+arr[i-1][j+1]+ arr[i+1][j-1]+ arr[i+1][j+1];  //diagonal neighbours
            direct = arr[i-1][j]+arr[i][j-1]+ arr[i+1][j]+ arr[i][j+1];    //direct neighbours
            neighbours = diagonal+direct;  //total neighbours
         }


            if(arr[i][j]==1 && (neighbours<2||neighbours>3))   // over population or underpopulated
                next[i][j]= 0;
            if(arr[i][j]==1 && (neighbours==2||neighbours==3))  //survival
                next[i][j]= 1;
            if(arr[i][j]==0 && neighbours==3){ //birth
                next[i][j]= 1;
                }

        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
             printf("%d",next[i][j]);
            if(j==column-1)
            printf("\n");
            }
    }
for(i=0;i<row;i++){
    for(j=0;j<column;j++){
        arr[i][j]=next[i][j];
    }
}

 }

    }








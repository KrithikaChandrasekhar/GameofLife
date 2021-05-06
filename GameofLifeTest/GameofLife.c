#include<stdio.h>
#include "Test.h"


int main()
{
   printf("The Known Matrix is:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
           printf("%d",arr[i][j]);
            if(j==3)
                printf("\n");
        }
    }
   checkcornerneighbours();
     for(i=0;i<4;i++){
        for(j=0;j<4;j++){
             if(i==0 && j==0){ //Top left corner
                neighbours=neighboursTL;
                if(neighboursTL==neighboursTLTest)
                    printf("arr[%d][%d] Test Passed\n",i,j);
                    else printf("arr[%d][%d] Test Failed\n",i,j);
             }
             if(i==0 && (j>0&&j<3)){  //top row leaving corners
                diagonal = arr[i+1][j-1]+arr[i+1][j+1];
                direct = arr[i][j-1]+arr[i][j+1]+arr[i+1][j];
                neighbours = diagonal+direct;
             }
             if(i==0 && j==3){ //Top right corner
                neighbours=neighboursTR;
                if(neighboursTR==neighboursTRTest)
                    printf("arr[%d][%d] Test Passed\n",i,j);
                    else printf("arr[%d][%d] Test Failed\n",i,j);
             }
             if((i>0 && i<3) && j==0){ //extreme Left Column leaving corners
                diagonal = arr[i-1][j+1]+arr[i+1][j+1];
                direct = arr[i-1][j]+arr[i][j+1]+arr[i+1][j];
                neighbours = diagonal+direct;
             }
             if(i==3 && j== 0){ //Bottom left corner
                neighbours=neighboursBL;
                if(neighboursBL==neighboursBLTest)
                    printf("arr[%d][%d] Test Passed\n",i,j);
                    else printf("arr[%d][%d] Test Failed\n",i,j);
             }
             if(i==3&&(j>0&&j<3)){ //Bottom row leaving corners
                diagonal = arr[i-1][j-1]+arr[i-1][j+1];
                direct = arr[i][j-1]+arr[i][j+1]+arr[i-1][j];
                neighbours = diagonal + direct;
             }

             if(i==3 && j==3){ // Bottom Right corner
                neighbours=neighboursBR;
                if(neighboursBR==neighboursBRTest)
                    printf("arr[%d][%d] Test passed\n",i,j);
                    else printf("arr[%d][%d] Test Failed\n",i,j);
             }

             if((i>0&&i<3)&& j==3){  // extreme right column leaving corners
                diagonal = arr[i-1][j-1]+arr[i+1][j-1];
                direct = arr[i-1][j]+arr[i+1][j]+arr[i][j-1];
                neighbours = diagonal + direct;
             }

            if((i>0&&i<3) && (j>0&&j<3)){// mid
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
      printf("The Next Gen Matrix is:\n");
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                 printf("%d",next[i][j]);
                 if(j==3)
                 printf("\n");
                }
            }



      for(i=0;i<4;i++){
           for(j=0;j<4;j++){
               if((testarr[i][j]==next[i][j]))
                printf("testarr[%d][%d] = next[%d][%d] Test Passed\n",i,j,i,j);
                else
                    printf("testarr[%d][%d] != next[%d][%d] Test Failed\n",i,j,i,j);
             }
           }
}



int checkcornerneighbours(){
for(i=0;i<4;i++){
        for(j=0;j<4;j++){
             if(i==0 && j==0){  //Top left corner
                diagonal = arr[i+1][j+1];
                direct = arr[i][j+1]+arr[i+1][j];
                neighboursTL = diagonal+direct;
              }

             if(i==0 && j==3){ //Top right corner
                diagonal = arr[i+1][j-1];
                direct = arr[i][j-1]+arr[i+1][j];
                neighboursTR = diagonal + direct;
             }

             if(i==3 && j== 0){ //Bottom left corner
                diagonal = arr[i-1][j+1];
                direct = arr[i-1][j]+arr[i][j+1];
                neighboursBL = diagonal + direct;
            }

             if(i==3 && j==3){ // Bottom Right corner
                diagonal = arr[i-1][j-1];
                direct = arr[i][j-1]+arr[i-1][j];
                neighboursBR = diagonal + direct;
            }
        }
      }
}








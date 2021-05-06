#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED


int arr[4][4];
int testarr[4][4];
arr[4][4] = {{1,1,0,0},{1,0,0,0},{0,0,1,1},{1,1,1,1}};  // passing known values to form 4x4 matrix
testarr[4][4]={{1,1,0,0},{1,0,1,0},{1,0,0,1},{0,1,0,1}};  //Expected next generation array
int neighboursTLTest= 2; neighboursTRTest=0; neighboursBLTest=1 , neighboursBRTest=3;// values for passing corner neighbours test
//int neighboursTLTest= 1; neighboursTRTest=2; neighboursBLTest=3 , neighboursBRTest=4; // values for failing corner neighbours test
int neighboursTL,neighboursTR,neighboursBL,neighboursBR;
int next[4][4],i,j, diagonal=0,direct=0,status=4;neighbours,teststatus=0;


int i,j;

int checkcornerneighbours(void);



#endif // TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


/* 
 * Determines if coord is in range between
 * offset (INCLUSIVE) and offset + size (EXCLUSIVE)
 */
int isInRange(int coord, int offset, int size) {
  // if coord is in range, return 1
  // else, return 0
  if ((coord >=offset) && coord < (offset+size)){
    return 1;
  }
  else
  {
    return 0;
  }
  
}


/*
 * Determines if coord is at border of offset or
 * offset + size
 */
int isAtBorder(int coord, int offset, int size) {
  // if coord is equal to offest or offset + size
  // return 1, else return 0
  if (coord==offset||coord==offset+size){
    return 1;
  }
  else
  {
    return 0;
  }
  

}

int max(int x1, int x2){
  if (x1>x2){
    return x1;
  }
  else{
    return x2;
  }
}


void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int w = max(size1,x_offset+size2);
  //compute the max of size1 and (y_offset + size2).  Call this h
  int h = max(size1,size2+y_offset);
  //count from 0 to h. Call the number you count with y

    //count from 0 to w. Call the number you count with x

      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *

      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #

      //else print a space
    //when you finish counting x from 0 to w, 
    //print a newline
  for (int y =0;y <= h;y++){
    for (int x = 0;x <= w;x++){
      if ((isInRange(x,x_offset,size2) && isAtBorder(y,y_offset,size2-1))||(isInRange(y,y_offset,size2)&& isAtBorder(x,x_offset,size2-1)))
      {
        printf("*");
      }
      else if  (((x< size1) && (y==0 || y==size1-1))|| (y<size1 && (x==0||x==size1-1)))
      {
          printf("#");
        }
      else
      {
        printf(" ");
      }



    }
    if (x<w){
    printf("\n");
    }
  }
}


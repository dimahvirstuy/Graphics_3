#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
  if (points->lastcol==points->cols) {
    grow_matrix(points,points->cols+1);
  }
  points->m[0][points->lastcol]=x;
  points->m[1][points->lastcol]=y;
  points->m[2][points->lastcol]=z;
  points->m[3][points->lastcol]=1;
  points->lastcol++;
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, 
	       double x0, double y0, double z0, 
	       double x1, double y1, double z1) {
  add_point(points,x0,y0,z0);
  add_point(points,x1,y1,z1);
}

/*======== void draw_lines() ==========
  Inputs:   struct matrix * points
  screen s
  color c 
  Returns: 
  Go through points 2 at a time and call draw_line to add that line
  to the screen
  ====================*/
void draw_lines( struct matrix * points, screen s, color c) {
  int x0,y0,x1,y1,col;
  col = 0;
  while (col < points->lastcol) {
    x0= points->m[0][col];
    y0= points->m[1][col];
    col++;
    x1= points->m[0][col];
    y1= points->m[1][col];
    
    draw_line(x0,y0,x1,y1,s,c);
    col++;
  }
}





void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (y0>y1) {
    int temp=y0;
    y0=y1;
    y1=temp;
    temp=x0;
    x0=x1;
    x1=temp;
  }
  if (x1 > x0 && y1 > y0 && x1 - x0 >= y1 - y0) {
    //1st octant
    int a = y1 - y0; //delta y
    int b = x0 - x1; //delta x
    int d = a + b/2; //change factor
    int x = x0; //initial x
    int y = y0; //initial y
    while (x < x1) {
      plot(s, c, x, y);
      x++;
      if (d > 0) {
	y++;
	d += b;
      }
      d += a;
    }
  }
  else if (x1 > x0 && y1 > y0 && x1 - x0 <= y1 - y0) {
    //2nd Octant
    int a = y1 - y0; //delta y
    int b = x0 - x1; //-delta x
    int d = b + a/2; //midpoint
    int x = x0; //initial x
    int y = y0; //initial y
    while (y < y1) {
      plot(s, c, x, y);
      y++;
      if (d < 0) {
	x++;
	d += a;
      }
      d += b;
    }
  }
  else if (x1 < x0 && y1 > y0 && x0 - x1 <= y1 - y0) {
    //3rd Octant
    int a = y1 - y0; //delta y
    int b = x0 - x1; //-delta x
    int d = b + a/2; //midpoint
    int x = x0; //initial x
    int y = y0; //initial y
    while (y < y1) {
      plot(s, c, x, y);
      y++;
      if (d > 0) {
	x--;
	d -= a;
      }
      d += b;
    }
  }
  else if (x1 < x0 && y1 > y0 && x0 - x1 >= y1 - y0) {
    //4th Octant 
    int a = y1 - y0; //delta y
    int b = x0 - x1; //-delta x
    int d = a + b/2; //midpoint
    int x = x0; //initial x
    int y = y0; //initial y
    while (x > x1) {
      plot(s, c, x, y);
      x--;
      if (d > 0) {
	y++;
	d -= b;
      }
      d += a;
    }
  }
  else {
    //raw_line(x1, y1, x0, y0, s, c); //switching coords will guarantee it's in one of these octants if it got to this point
  }
} //end draw_line
  

#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
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
}
  
  

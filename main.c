#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);
  color c;
  c.green=255;


  struct matrix * m=new_matrix(4,4);
  struct matrix * n=new_matrix(4,3);
  m->lastcol=4;
  n->lastcol=3;
  

  printf("ident test\n");
  ident(m);
  print_matrix(m);

  n->m[0][0]=3;
  n->m[0][1]=7;
  n->m[3][2]=14;
  n->m[2][2]=12;
  printf("\nprinting filled matrix\n");
  print_matrix(n);

  printf("\ntesting matrix_mult with identity matrix\nbefore:\n");
  print_matrix(n);
  matrix_mult(m,n);
  printf("\nafter:\n");
  print_matrix(n);

  printf("\ntesting matrix_mult with not identity matrix\n");
  m->m[0][2]=14;
  m->m[1][0]=8;
  m->m[2][2]=17;
  print_matrix(m);
  printf("\nmultipled by\n");
  print_matrix(n);
  matrix_mult(m,n);
  printf("\nresult\n");
  print_matrix(n);

  free_matrix(m);
  free_matrix(n);
  
  struct matrix *edges;

  edges = new_matrix(4, 4);

  printf("adding edges and points\n");
  add_edge(edges,100,400,0,100,300,0);
  add_edge(edges,0,200,0,100,300,0);
  add_edge(edges,0,50,0,10,300,0);
  add_edge(edges,0,300,0,200,350,0);
  add_edge(edges,150,50,0,200,0,0);
  add_edge(edges,100,400,0,200,400,0);
  print_matrix(edges);
  add_edge(edges,20,30,0,225,440,0);
  add_edge(edges,350,100,0,200,250,0);
  add_edge(edges,200,450,0,400,250,0);
  add_edge(edges,100,400,0,350,350,0);
  add_edge(edges,200,400,0,400,400,0);
  add_edge(edges,30,40,0,400,400,0);
  add_edge(edges,40,350,0,450,400,0);
  add_edge(edges,450,400,0,500,350,0);
  add_edge(edges,400,350,0,500,350,0);
  add_edge(edges,300,300,0,10,300,0);
  add_edge(edges,300,300,0,0,40,0);
  add_edge(edges,0,300,0,200,40,0);
  add_edge(edges,2000,300,0,400,300,0);
  add_edge(edges,300,300,0,0,20,0);
  add_edge(edges,200,300,0,250,200,0);
  add_edge(edges,500,300,0,300,100,0);
  add_edge(edges,500,300,0,0,40,0);
  add_edge(edges,0,300,0,200,40,0);
  draw_lines(edges, s, c);
  save_ppm(s,"image.ppm");
  display(s);
  
  free_matrix( edges );
}

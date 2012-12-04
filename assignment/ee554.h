/***********************************************************HeaderBegin*******
 *                                                                         
 * File:        ee554.h
 *
 * Author:      Noel O'Connor
 *
 * Created:     02/08/2000
 *                                                                         
 * Description: Header file for EE554 software library
 *
 * Modified:   
 *              
 ***********************************************************HeaderEnd*********/


#ifndef __EE554_H_
#define __EE554_H_

/************************    Include files    ********************************/

#include <stdio.h>

/************************ Image and pixel stuctures **************************/

typedef int pel;
typedef float block_t[8][8];
typedef int mblock_t[16][16];

struct ee554_image
{
  int width;
  int height;
  pel *pels; 
};
typedef struct ee554_image image;

struct ee554_sequence 
{
  int length;
  image *images[1000]; 
};
typedef struct ee554_sequence sequence;


/************************ image allocation and freeing ***********************/

image *alloc_image(int, int);
image *clone_image(image * img);
void free_image(image *);

/************************** image access functions ***************************/

int get_image_width(image *);
int get_image_height(image *);

/************************** image I/O functions ******************************/

image *pgm_load_image(char *filename);
void pgm_write_image(image *, char *);

/*********************** sequence functions **********************************/

sequence * load_sequence(char *seqname);
void free_sequence(sequence *seq);
int get_sequence_width(sequence *seq);
int get_sequence_height(sequence *seq);
int get_sequence_length(sequence *seq);
image **get_sequence_images(sequence *seq);

/******************************* PSNR functions ******************************/

double calc_PSNR_image(image *, image *);

/**************************** entropy functions ******************************/

double calc_entropy_image(image *, int);

/**************************** image utility functions ************************/

void sub_image(image *, image *, image *);
void abs_sub_image(image *, image *, image *);
void create_diff_image(image *, image *, image *);

/**************************** block extraction and insertion functions *******/

void get_block(image *img, int x, int y, block_t block);
void put_block(image *img, int x, int y, block_t block);

/*********************** macroblock extraction and insertion functions *******/

void get_mblock(image *img, int x, int y, mblock_t mb);
void put_mblock(image *img, int x, int y, mblock_t mb);

/************************ printing functions *********************************/

void print_block(block_t block);

#endif

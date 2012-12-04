/***********************************************************HeaderBegin*******
 *                                                                         
 * File:        ee554_lib.h
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


#ifndef __EE554_LIB_H_
#define __EE554_LIB_H_

/************************    Include files    ********************************/

#include <stdio.h>

/******************** macro for estimating bits required *********************/

#ifndef log2
#define log2(x) (log10(x)/log10(2))
#endif

/************************** image access functions ***************************/

pel *get_image_pels(image *);
void put_image_width(image *, int);
void put_image_height(image *,int);

/******************************** I/O functions ******************************/

void pgm_read_image(char *, image *);
void pgm_read_image_header(char *, int *, int *, int *);
void pgm_read_image_header_bytes(FILE *,int *, int *, int *);

/******************************* PSNR functions ******************************/

double calc_MSE_image(image *, image *);

/********************** bit estimation functions ***  ************************/

int estimate_bits_image(image *, int );
int estimate_bits_pel(pel );
int estimate_bits_pel_signed(pel );

/**************************** image utility functions ************************/

void copy_image(image *, image *);

#endif

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

 
float **malloc2d(int);
void free_mat2d(float **, int);
void dct(float **, float **, int);
void idct(float **, float **, int);
void quantize(float **, float **, int, int);
void dequantize(float **, float **, int, int);

#endif

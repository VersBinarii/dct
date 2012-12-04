#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

 
float **malloc2d(int size);
void free2d(float **p);
void dct(float **, float **, int);
void idct(float **, float **, int);
void quantize(float **, float **, int, int);
void dequantize(float **, float **, int, int);

#endif

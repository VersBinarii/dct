#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

void dct(float **, float **, int);
void idct(float **, float **, int);
void quantize(float **, float **, int, int);
void dequantize(float **, float **, int, int);

#endif

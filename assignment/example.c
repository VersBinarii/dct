/***********************************************************HeaderBegin*******
 *                                                                         
 * File:        example.c
 *
 * Author:      Noel O'Connor, Vivien Chappelier
 *
 * Created:     02/08/2000
 *                                                                         
 * Description: Source file for EE554 software library
 *
 * Modified:    13/07/2001 - Vivien Chappelier:
 *                ported to the new EE554 library
 *                added example of how to use macroblock functions
 *              
 ***********************************************************HeaderEnd*********/

/************************    include files    ********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ee554.h"    /* EE554 software library           */
#include "example.h"  /* Header file for this source file */

#include "transform.h"
/***********************************************************CommentBegin******
 *
 * -- main -- 
 *
 * Author :             Noel O'Connor	
 *	
 *
 * Created :            02/08/2000
 *	
 *
 * Description :        Example of using the ee554 software library
 *		
 * 
 * Arguments in :       Two command line arguments: 
 *                      input PGM file name
 *                      output PGM file name 
 *	                
 *
 * Arguments in/out :	None
 *	
 *
 * Arguments out :	None
 *	
 *
 * Return values :      EXIT_SUCCESS	
 *
 *
 * Side effects :       None
 *	
 *
 * See also :           threshold_image()
 *	
 *
 * Modified :           13/07/2001 - Vivien Chappelier :
 *                        simplified image handling using load and 
 *                        clone functions.
 *
 *
 ***********************************************************CommentEnd********/

int main(int argc, char *argv[])
{
  image *img_in,       /* pointer to input image data structure  */
        *img_out;      /* pointer to output image data structure */

  char  file_in[100],  /* input file name */
        file_out[100]; /* output file name */

  /* Process input arguments */
  if(argc != 3)
    {
      fprintf(stdout,"Usage: example [input PGM file name] [output PGM file name]\n");
      exit(0);
    }
  else
    {
      strcpy(file_in, argv[1]);
      strcpy(file_out, argv[2]);
    }

  /* Load the input image */
  img_in = pgm_load_image(file_in);
  
  /* Make a clone of it to store the result */
  img_out = clone_image(img_in);

  /* Threshold the input image and store the result in the output image */
  threshold_image(img_in, img_out);

  /* Now write out the output image */
  printf("Writing out %s\n",file_out);
  pgm_write_image(img_out, file_out);

  /* We must deallocate the memory for each image before we finish */
  free_image(img_in);
  free_image(img_out);

  return(EXIT_SUCCESS);
}

/***********************************************************CommentBegin******
 *
 * -- threshold_image -- 
 *
 * Author :             Noel O'Connor	
 *	
 *
 * Created :            02/08/2000
 *	
 *
 * Description :        Thresholds each block in an image and stores 
 *                      the result in another image.
 *		
 * 
 * Arguments in :       image *img1 - pointer to input image data structure
 *                      image *img2 - pointer to output image data structure
 *	                
 *
 * Arguments in/out :	None
 *	
 *
 * Arguments out :	None
 *	
 *
 * Return values :      None
 *
 *
 * Side effects :       None
 *	
 *
 * See also :           main()
 *	
 *
 * Modified :           13/07/2001 - Vivien Chappelier :
 *                        changed to use macroblocks instead of pixels.
 *
 *
 ***********************************************************CommentEnd********/

void threshold_image(image *img1, image *img2)
{
  block_t blk, out_blk;         /* macroblock to be processed */ 
  int   width,         /* width of image */
        height,        /* height of image */ 
        x, y,          /* macroblock loop indexes */
        i, j;          /* pixel loop indexes */

  /* Get image width and height */
  width = get_image_width(img1);
  height = get_image_height(img1);

  /* Scan through the image and process macroblocks */
  for(y = 0; y < height; y+=8) {  /* block width is 8 pixels */
    for(x = 0; x < width; x+=8) { /* block height is 8 pixels */

      /* get a macroblock from the input image */
      get_block(img1, x, y, blk);
      

      dct(out_blk, blk, 8);
      idct(out_blk, blk, 8);
        
/*
*       Scan through the macroblock and threshold
*       i.e. if pixel < 128 then pixel = 0, else pixel = 255 
*      for(i = 0; i < 8; i++) {
*	for(j = 0; j < 8; j++) {
*
*	  if(blk[i][j] < 128)
*	    blk[i][j] = 0;
*	  else 
*	    blk[i][j] = 255;
*	
*	}
*      }
*/
      /* put the macroblock in the output image */
      put_block(img2, x, y, blk);
    }
  }
  return;
}

#!/bin/bash
#===============================================================================
#
#          FILE:  runassignment.sh
# 
#         USAGE:  ./runassignment.sh 
# 
#   DESCRIPTION:  This script will run the asignment program to generete the pictures
#                   with varying level of Q and calculate the SNR for each
# 
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#         NOTES:  ---
#        AUTHOR:  Krzysztof Grobelak (), 
#       COMPANY:  
#       VERSION:  1.0
#       CREATED:  09/12/12 12:00:43 GMT
#      REVISION:  ---
#===============================================================================

ext=.pgm
camera_in=camera
text_in=text
output_=out_images/
assignment=./assignment

for i in {10..100..10}
do
    #run the program passing in the input picture specyfying output picture name and Q value
    "$assignment" images/"$camera_in""$ext" "$output_""$camera_in"_"$i""$ext" "$i"
done

for i in {10..100..10}
do
    #run the program passing in the input picture specyfying output picture name and Q value
    "$assignment" images/"$text_in""$ext" "$output_""$text_in"_"$i""$ext" "$i"
done

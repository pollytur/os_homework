#!/bin/bash

#the 1st duplicates number was 427 when 1 process was run in the background

while True
do
	path="/Users/polinaturiseva/Desktop/оси/week5/ex2.txt"
	touch $path
	if [ -s /tmp/myfile.txt ]
	then 
		# locks the file
		chflags nouchg $path 
		tee -a $path <<< "1"
		# unlocks the file
		chflags uchg $path
	else
		chflags nouchg $path
		tag=$(tail -n 1 $path)
		sum=$((tag+1))
		echo $sum >> $path
		chflags uchg $path
	fi
done
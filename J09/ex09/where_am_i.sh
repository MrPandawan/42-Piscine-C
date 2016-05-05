#!/bin/sh
VAR=$(ifconfig | grep -w inet | cut -d ' ' -f2)
if [ VAR != 0 ]
hen
	echo "$VAR"
else
	echo "je suis perdu!"
fi

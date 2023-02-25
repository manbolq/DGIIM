#!/bin/bash

if (($1>$2))
then
touch $(($1*$2))_multi.txt
elif (($2>$1))
then
echo $(($2-$1))
else
echo "son el mismo numero"
fi

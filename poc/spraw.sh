#!/usr/bin/env bash

g++ poc.cpp -o poc.exe
g++ spraw.cpp -o spraw.exe
i=0
while [ $i -le 2 ]
do 
time ./poc.exe < poc$i.in > wynik.txt
diff -q poc$i.out wynik.txt
((i++))
done
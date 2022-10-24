#!/usr/bin/env bash

g++ poc.cpp -o poc.exe
g++ spraw.cpp -o spraw.exe
i=0
while [ $i -le 2 ]
do 
./poc.exe < poc$i.in > wynik.txt
./spraw.exe < poc$i.out >> res.txt
((i++))
done
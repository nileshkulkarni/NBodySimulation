#!/bin/bash
#script to compile codes

qmake -project
qmake
make
./colliding-mice

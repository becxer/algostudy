#!/bin/sh
rm $(find . -type f -perm +111 -maxdepth 1)
rm -r *.dSYM

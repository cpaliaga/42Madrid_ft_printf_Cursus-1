#!/bin/sh
git status
git add .
git commit -m date $1 
git push
git status

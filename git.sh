#!/bin/bash

git add -A *
msg="add some new exerises,"$1
git commit -a -m "$msg"
sleep 5
git push origin master

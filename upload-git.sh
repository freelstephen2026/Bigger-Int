#!/bin/bash

git pull
git init

git add --all

git commit -m "Implemented addition of 64-bit unsigned integers along with overflow data"

git remote add origin https://github.com/freelstephen2026/Bigger-Int
git push origin master














# Set the username and email address for git
# git config --global user.name "freelstephen2026"
# git config --global user.email "freelstephen3@gmail.com"

# echo "Makefile" >> .gitignore

# Stage your changes
# git add --all

# Commit your changes
# git commit -m "addition of 64-bit unsigned integers along with overflow data"

# Push your changes to GitHub on the master branch
# git push https://github.com/myaccount/somerepository.git master
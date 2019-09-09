#!/bin/bash
echo "Good Day Friend, building all submodules while checking out from MASTER branch."
<<<<<<< HEAD

git submodule update 
git submodule foreach git checkout master 
git submodule foreach git pull origin master 
=======
git submodule update 
git submodule foreach git checkout master 
git submodule foreach git pull origin master 
git checkout asmr
git pull
>>>>>>> master

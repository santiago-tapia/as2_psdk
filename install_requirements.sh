#! /usr/bin/bash

echo "Installing third parties dependencies..."

cd ..

vcs import < as2_psdk/depends.repos

cd ThirdParties/Payload-SDK

git checkout release/v3.5

touch COLCON_IGNORE
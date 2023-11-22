#! /usr/bin/bash

echo "Installing third parties dependencies..."

# Change to parent dir if neccesary
WORKINGDIR=$(pwd)
PACKAGEDIR='as2_psdk'
if [[ "$WORKINGDIR" == *"$PACKAGEDIR" ]]; then
  cd ..
fi

# Import source repos
vcs import < as2_psdk/depends.repos

cd ThirdParties/Payload-SDK

git checkout release/v3.5

# Ignore Payload_SDK since is already built
touch COLCON_IGNORE

wget https://raw.githubusercontent.com/ament/ament_lint/rolling/ament_uncrustify/ament_uncrustify/configuration/ament_code_style.cfg
mv ament_code_style.cfg uncrustify.cfg

#!/usr/bin/env bash

set -e

# make sure that we are under project folder
mkdir -p build
cd build

# build handy
TARGET_COMMIT_ID=e3635160a7de7a65d58120df77d5c94b5115e72e
TARGET_INSTALL_PATH=thirdparty/handy_install
TARGET_PATH=thirdparty/handy

if [ ! -d ${TARGET_INSTALL_PATH}/.git ]; then
    git clone https://github.com/yedf/handy.git ${TARGET_INSTALL_PATH}
fi

pushd ${TARGET_INSTALL_PATH}
git checkout ${TARGET_COMMIT_ID}
make
popd

mkdir -vp ${TARGET_PATH}/include/handy/
mkdir -vp ${TARGET_PATH}/lib/
cp -f ${TARGET_INSTALL_PATH}/handy/*.h ${TARGET_PATH}/include/handy/
cp -f ${TARGET_INSTALL_PATH}/libhandy.a ${TARGET_PATH}/lib/

# build coho
cmake ..
make

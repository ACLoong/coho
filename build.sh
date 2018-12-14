#!/usr/bin/env bash

set -e

# make sure that we are under project folder
mkdir -p build
cd build

# build handy
HANDY_TARGET_COMMIT_ID=e3635160a7de7a65d58120df77d5c94b5115e72e
HANDY_TARGET_INSTALL_PATH=thirdparty/handy_install
HANDY_TARGET_PATH=thirdparty/handy

if [ ! -d ${HANDY_TARGET_INSTALL_PATH}/.git ]; then
    git clone https://github.com/yedf/handy.git ${HANDY_TARGET_INSTALL_PATH}
fi

pushd ${HANDY_TARGET_INSTALL_PATH}
git checkout ${HANDY_TARGET_COMMIT_ID}
make
popd

mkdir -vp ${HANDY_TARGET_PATH}/include/handy/
mkdir -vp ${HANDY_TARGET_PATH}/lib/
cp -f ${HANDY_TARGET_INSTALL_PATH}/handy/*.h ${HANDY_TARGET_PATH}/include/handy/
cp -f ${HANDY_TARGET_INSTALL_PATH}/libhandy.a ${HANDY_TARGET_PATH}/lib/

#build minunit
MINUNIT_TARGET_COMMIT_ID=8af0cf5b675dc0a070475659a54ec044f1a6b4d0
MINUNIT_TARGET_INSTALL_PATH=thirdparty/minunit_install
MINUNIT_TARGET_PATH=thirdparty/minunit

if [ ! -d ${MINUNIT_TARGET_INSTALL_PATH}/.git ]; then
    git clone https://github.com/siu/minunit.git ${MINUNIT_TARGET_INSTALL_PATH}
fi

mkdir -vp ${MINUNIT_TARGET_PATH}/include/
cp -f ${MINUNIT_TARGET_INSTALL_PATH}/minunit.h ${MINUNIT_TARGET_PATH}/include

# build coho
cmake ..
make

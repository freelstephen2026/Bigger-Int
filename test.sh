./clean.sh
cmake .
make
make install

build/bin/test

read input

rm -rf CMakeFiles
rm -rf build/bin
rm libint128.so libthis.so.1 libthis.so.1.0
rm CMakeCache.txt cmake_install.cmake
rm install_manifest.txt
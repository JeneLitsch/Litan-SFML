cmake\
	-S .\
	-B build\
	-D CMAKE_CXX_COMPILER=clang++
cd build
make -j16
cd -
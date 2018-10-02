include environment.conf

CFLAGS=-std=c++14
LIBS=-ltiff

all: $(utils_path)/comparator $(tiff_utils_path)/tifGenerator

$(utils_path)/comparator: $(utils_path)/comparator.cpp
	g++ $(CFLAGS) $(utils_path)/comparator.cpp -o $(utils_path)/comparator

$(tiff_utils_path)/tifGenerator: $(tiff_utils_path)/tifGenerator.cpp
	g++ $(CFLAGS) $(tiff_utils_path)/tifGenerator.cpp -o $(tiff_utils_path)/tifGenerator $(LIBS)
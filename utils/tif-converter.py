from osgeo import gdal
import sys
import glob as gb

tif_files = gb.glob('*.tif')

for tif_file in tif_files:
    curr_dataset = gdal.Open(tif_file, gdal.GA_ReadOnly)
    converted_file = open(tif_file.replace('.tif', '.txt'), 'w') 

    for x in range(1, curr_dataset.RasterCount + 1):
        band = curr_dataset.GetRasterBand(x)
        array = band.ReadAsArray()

        for i in xrange(len(array)):
            converted_file_string = ''

            for j in xrange(len(array[i])):
                if j == 0:
                    converted_file_string += str(array[i][j])
                else:
                    converted_file_string += ' ' + str(array[i][j])


            converted_file.write(converted_file_string + '\n')

    converted_file.close()
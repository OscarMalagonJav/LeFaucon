#ifndef  ADDOPERATION_H
#define  ADDOPERATION_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkPNGImageIO.h"
#include "itkImage.h"
#include "itkAddImageFilter.h"
#include "itkMedianImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"

typedef itk::Image<unsigned char, 2>  ImageType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::AddImageFilter <ImageType, ImageType, ImageType> AddImageFilterType;
typedef itk::MedianImageFilter<ImageType, ImageType> FilterType;
typedef itk::RescaleIntensityImageFilter< ImageType, ImageType > RescaleFilterType;

struct minMax
{
  int minimum;
  int maximum;
};

minMax findMinAndMaxValues(ImageType::Pointer img);
ImageType::Pointer addImages(int argc, char * argv[]);

#endif
#ifndef AVERAGEFILTER_H
#define AVERAGEFILTER_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImage.h"
#include "itkAddImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"

typedef itk::Image<unsigned char, 2>  ImageType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::AddImageFilter <ImageType, ImageType, ImageType> AddImageFilterType;
typedef itk::RescaleIntensityImageFilter< ImageType, ImageType > RescaleFilterType;
struct minMax
{
  int minimum;
  int maximum;
};

minMax findMinAndMaxValues(ImageType::Pointer img);
ItkImageType::Pointer applyAverageImage(int argc, char * argv[]);

#endif
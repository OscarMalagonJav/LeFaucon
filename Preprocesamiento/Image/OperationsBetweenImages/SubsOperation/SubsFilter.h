#ifndef SUBSFILTER_H
#define SUBSFILTER_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImage.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkSubtractImageFilter.h"
#include <typeinfo>

typedef itk::Image<unsigned char, 2>  ImageType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::SubtractImageFilter <ImageType, ImageType, ImageType >SubtractImageFilterType;

#endif
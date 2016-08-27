#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkMedianImageFilter.h"

typedef itk::Image<unsigned char, 2 > ItkImageType;
typedef itk::ImageFileReader<ItkImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
typedef itk::MedianImageFilter<ItkImageType, ItkImageType > MedianFilterType;

ItkImageType::Pointer applyMedianFilter(std::string inputImageName, int radius);
#endif

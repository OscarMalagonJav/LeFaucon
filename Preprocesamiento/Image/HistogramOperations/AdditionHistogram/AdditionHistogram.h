#ifndef ADDITIONHISTOGRAM_H
#define ADDITIONHISTOGRAM_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkBinomialBlurImageFilter.h"
#include "itkImageRegionConstIterator.h"
#include <typeinfo>
#include "itkRescaleIntensityImageFilter.h"

typedef itk::Image< unsigned char, 2 >   ItkImageType;
typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
typedef itk::RescaleIntensityImageFilter< ItkImageType, ItkImageType > RescaleFilterType;

ItkImageType::Pointer applyAdditionHistogram(std::string inputImageName, int value);

#endif

#ifndef MULTIPLICATIONHISTOGRAM_H
#define MULTIPLICATIONHISTOGRAM_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImageRegionConstIterator.h"
#include "itkRescaleIntensityImageFilter.h"

typedef itk::Image< unsigned char, 2 >   ItkImageType;
typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;

ItkImageType::Pointer applyMultiplicationHistogram(std::string inputImageName, float value);

#endif

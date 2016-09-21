#ifndef GAUSSIANPYRAMIDS
#define GAUSSIANPYRAMIDS

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkRecursiveMultiResolutionPyramidImageFilter.h"
#include "itkImageFileWriter.h"
#include "itkRescaleIntensityImageFilter.h"
#include <list>


typedef itk::Image<float, 2> ItkFloatImageType;
typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::ImageFileReader<UnsignedCharImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::RecursiveMultiResolutionPyramidImageFilter<UnsignedCharImageType, ItkFloatImageType> RecursiveMultiResolutionPyramidImageFilterType;
typedef itk::RescaleIntensityImageFilter< ItkFloatImageType, UnsignedCharImageType > RescaleFilterType;

std::list<UnsignedCharImageType::Pointer> gaussianPyramid(std::string inputImageName, int numberOfLevels, float maximumError);
#endif
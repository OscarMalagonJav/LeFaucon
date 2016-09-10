#ifndef GAUSSIANPYRAMIDS
#define GAUSSIANPYRAMIDS

#include "itkImage.h"
#include "itkImageFileReader.h"
#include <itkMultiResolutionPyramidImageFilter.h>
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"


typedef itk::Image<float, 2> ItkFloatImageType;
typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::CastImageFilter< ItkFloatImageType, UnsignedCharImageType > CastFilterType;
typedef itk::ImageFileReader<UnsignedCharImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::MultiResolutionPyramidImageFilter< UnsignedCharImageType, UnsignedCharImageType > ImagePyramidType;

UnsignedCharImageType::Pointer gaussianPyramid(std::string inputImageName, int numberOfLevels);
#endif
#ifndef CANNYEDGEDETECTOR_H
#define CANNYEDGEDETECTOR_H

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkCannyEdgeDetectionImageFilter.h"
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"

typedef itk::Image<float, 2> ItkFloatImageType;
typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::CastImageFilter< UnsignedCharImageType,ItkFloatImageType> CastToFloatFilterType;
typedef itk::CannyEdgeDetectionImageFilter< ItkFloatImageType, ItkFloatImageType > CannyFilterType;
typedef itk::RescaleIntensityImageFilter< ItkFloatImageType, UnsignedCharImageType >  RescaleFilterType;
typedef itk::ImageFileReader<UnsignedCharImageType>        ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;

UnsignedCharImageType::Pointer applyCannyEdgeDetector(std::string inputImageName, float variance ,float upperThreshold ,float lowerThreshold);

#endif
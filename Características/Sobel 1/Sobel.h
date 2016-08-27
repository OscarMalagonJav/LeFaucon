#ifndef SOBEL_H
#define SOBEL_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkSobelEdgeDetectionImageFilter.h"
#include "itkCastImageFilter.h"

typedef itk::Image<unsigned char, 2 > ItkUnsignedCharImageType;
typedef itk::Image<float, 2 > ItkFloatImageType;
typedef itk::CastImageFilter< ItkFloatImageType, ItkUnsignedCharImageType > CastFilterType;    
typedef itk::ImageFileReader<ItkFloatImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<ItkUnsignedCharImageType> ImageFileWriterType;
typedef itk::SobelEdgeDetectionImageFilter<ItkFloatImageType, ItkFloatImageType> SobelFilterType;

ItkUnsignedCharImageType::Pointer applySobel(std::string inputImage);

#endif
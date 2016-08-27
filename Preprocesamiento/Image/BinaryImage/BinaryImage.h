#ifndef BINARYIMAGE_H
#define BINARYIMAGE_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkBinaryThresholdImageFilter.h"

typedef itk::Image< unsigned char, 2 >   ItkImageType;
typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
typedef itk::BinaryThresholdImageFilter <ItkImageType, ItkImageType> BinaryThresholdImageFilterType;

ItkImageType::Pointer createBinayImage(std::string inputImageName,int lowerThreshold, int upperThreshold);

#endif

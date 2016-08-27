#ifndef THRESHOLDING_H
#define THRESHOLDING_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"

typedef itk::Image<unsigned char, 2 > ItkImageType;
typedef itk::ImageFileReader<ItkImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;

ItkImageType::Pointer thresholdImage(std::string inputImageName, int threshold);

#endif

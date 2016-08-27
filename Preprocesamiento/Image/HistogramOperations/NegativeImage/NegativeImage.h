#ifndef NEGATIVEIMAGE_H
#define NEGATIVEIMAGE_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkInvertIntensityImageFilter.h"

typedef itk::Image< unsigned char, 2 >   ItkImageType;
typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
typedef itk::InvertIntensityImageFilter <ItkImageType> InvertIntensityImageFilterType;

ItkImageType::Pointer negativeImage(std::string inputImageName, int maximum);

#endif

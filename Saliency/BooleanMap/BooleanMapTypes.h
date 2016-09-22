#ifdef BOOLEANMAPTYPES_H
#define BOOLEANMAPTYPES_H

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkBinaryThresholdImageFilter.h"
#include <list>

typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::ImageFileReader<UnsignedCharImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::BinaryThresholdImageFilter< UnsignedCharImageType, UnsignedCharImageType > ThresholdFilterType;
#endif

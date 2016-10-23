#ifndef ATTENTIONMAP_H
#define ATTENTIONMAP_H

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkBinaryDilateImageFilter.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkNormalizeImageFilter.h"
#include "itkCastImageFilter.h"
#include <list>

typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::Image< float, 2 >  FloatImageType;
typedef itk::BinaryBallStructuringElement< unsigned char, 2 > KernelType;
typedef itk::ImageFileReader<UnsignedCharImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::BinaryDilateImageFilter< UnsignedCharImageType, UnsignedCharImageType, KernelType >  DilateFilterType;
typedef itk::NormalizeImageFilter< FloatImageType, FloatImageType >  NormalizeFilterType; 
typedef itk::CastImageFilter< UnsignedCharImageType, FloatImageType > CastToFloat; 
typedef itk::CastImageFilter< FloatImageType,UnsignedCharImageType > CastToUnsignedChar;  

UnsignedCharImageType::Pointer calculateAttentionMap(UnsignedCharImageType::Pointer booleanMap);
UnsignedCharImageType::Pointer dilateImage(UnsignedCharImageType::Pointer inputImage);
UnsignedCharImageType::Pointer normalizeImage(UnsignedCharImageType::Pointer inputImage);
std::list<UnsignedCharImageType::Pointer> AttentionMapsList(std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps);

#endif
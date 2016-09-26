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
#include "itkAddImageFilter.h"
#include <itkMultiplyImageFilter.h>
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
typedef itk::AddImageFilter < UnsignedCharImageType, UnsignedCharImageType, UnsignedCharImageType > AddImageFilterType;
typedef itk::MultiplyImageFilter<UnsignedCharImageType, UnsignedCharImageType, UnsignedCharImageType > MultiplyImageFilterType;
typedef itk::AddImageFilter <UnsignedCharImageType, UnsignedCharImageType ,UnsignedCharImageType > AddImageFilterType;

std::list<UnsignedCharImageType::Pointer> generateAttentionMapList(std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps);
UnsignedCharImageType::Pointer calculateAttentionMap(UnsignedCharImageType::Pointer booleanMap);
UnsignedCharImageType::Pointer dilateImage(UnsignedCharImageType::Pointer inputImage);
UnsignedCharImageType::Pointer normalizeImage(UnsignedCharImageType::Pointer inputImage);
UnsignedCharImageType::Pointer generateMeanAttentionMapImage(std::list<UnsignedCharImageType::Pointer> imagesList);

#endif
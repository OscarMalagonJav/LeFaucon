#ifndef BOOLEANMAP_H
#define BOOLEANMAP_H

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkBinaryThresholdImageFilter.h"
#include "itkBinaryMorphologicalOpeningImageFilter.h"
#include <list>

typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::ImageFileReader<UnsignedCharImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::BinaryBallStructuringElement< unsigned char, 2 > KernelType;
typedef itk::BinaryMorphologicalOpeningImageFilter< UnsignedCharImageType, UnsignedCharImageType, KernelType > OpeningMorphologicalOperationFilter;
typedef itk::BinaryThresholdImageFilter< UnsignedCharImageType, UnsignedCharImageType > ThresholdFilterType;

std::list<UnsignedCharImageType::Pointer> generateBooleanMaps(std::list<std::string> listOfFeatureImagesPath, int numberOfThresholds);
std::list<UnsignedCharImageType::Pointer> loadFeatureImages(std::list<std::string> listOfFeatureImagesPath);
std::list<int> calculateListOfThresholds(int numberOfThresholds);
UnsignedCharImageType::Pointer thresholdingImage(int thresholdValue, UnsignedCharImageType::Pointer inputImage, bool isNegative);
UnsignedCharImageType::Pointer openingMorphologicalOperation(UnsignedCharImageType::Pointer inputImage, bool isNegative);

#endif
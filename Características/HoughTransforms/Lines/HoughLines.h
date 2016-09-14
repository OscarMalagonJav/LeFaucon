#ifndef HOUGHLINES_H
#define HOUGHLINES_H

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIterator.h"
#include "itkThresholdImageFilter.h"
#include "itkMinimumMaximumImageCalculator.h"
#include "itkGradientMagnitudeImageFilter.h"
#include "itkDiscreteGaussianImageFilter.h"
#include "itkMath.h"
#include <itkHoughTransform2DLinesImageFilter.h>
#include <list>

typedef itk::Image<unsigned char, 2> AccumulatorImageType;
typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::ImageFileReader<UnsignedCharImageType>        ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::HoughTransform2DLinesImageFilter<unsigned char,unsigned char> HoughTransformFilterType;

UnsignedCharImageType::Pointer applyHoughTransformForLines(std::string inputImageName, int numberOfLines,float threshold,float discRadius,float variance,float angleResolution);

#endif
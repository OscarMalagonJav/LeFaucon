#ifndef HOUGHCIRCLES_H
#define HOUGHCIRCLES_H

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIterator.h"
#include "itkThresholdImageFilter.h"
#include "itkMinimumMaximumImageCalculator.h"
#include "itkGradientMagnitudeImageFilter.h"
#include "itkDiscreteGaussianImageFilter.h"
#include "itkMath.h"
#include "itkHoughTransform2DCirclesImageFilter.h"
#include <list>

typedef itk::Image<unsigned char, 2> AccumulatorImageType;
typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::ImageFileReader<UnsignedCharImageType>        ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::HoughTransform2DCirclesImageFilter<unsigned char,unsigned char> HoughTransformFilterType;
typedef HoughTransformFilterType::CirclesListType CirclesListType;

UnsignedCharImageType::Pointer applyHoughTransformForCircles(std::string inputImageName, int numberOfCircles, float radiusMin, float radiusMax,float sigmaGradient,float threshold,float discRadiusRatio,float variance,float sweepAngle);

#endif
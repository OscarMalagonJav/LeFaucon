#ifndef DISCRETEGAUSSIAN_H
#define DISCRETEGAUSSIAN_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkDiscreteGaussianImageFilter.h"
#include "itkCastImageFilter.h"

typedef itk::Image<unsigned char, 2 > ItkImageType;
typedef itk::Image<float, 2 > ItkImageTypeFloat;
typedef itk::CastImageFilter< ItkImageTypeFloat, ItkImageType > CastFilterType;
typedef itk::ImageFileReader<ItkImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;//Change the output image by ItkImageTypeFloat
typedef itk::DiscreteGaussianImageFilter<ItkImageType, ItkImageTypeFloat> discreteGaussianFilterType; //Change the output image by ItkImageTypeFloat

ItkImageType::Pointer applyDiscreteGaussianFilter(std::string inputImageName,double variance);

#endif

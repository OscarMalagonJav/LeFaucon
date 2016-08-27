#ifndef IMAGECONVOLUTION_H
#define IMAGECONVOLUTION_H

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkConvolutionImageFilter.h"
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"

typedef itk::Image<float, 2> ItkFloatImageType;
typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::CastImageFilter< ItkFloatImageType, UnsignedCharImageType > CastFilterType;
typedef itk::ImageFileReader<ItkFloatImageType>        ImageFileReaderType;
typedef itk::ConvolutionImageFilter<ItkFloatImageType> ConvolveItkFloatImageType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;

void CreateKernel(ItkFloatImageType::Pointer kernel, int width, float kernelValues[]);
UnsignedCharImageType::Pointer convolveImage(std::string inputImage, int width, float kernelValues[]);

#endif

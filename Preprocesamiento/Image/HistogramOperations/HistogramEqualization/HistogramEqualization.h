#ifndef HISTOGRAMEQUALIZATION_H
#define HISTOGRAMEQUALIZATION_H
#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkAdaptiveHistogramEqualizationImageFilter.h"
#include <itkRescaleIntensityImageFilter.h>

  typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
  typedef itk::AdaptiveHistogramEqualizationImageFilter< ItkImageType > AdaptiveHistogramEqualizationImageFilterType;
  typedef itk::RescaleIntensityImageFilter< ItkImageType, ItkImageType > RescaleFilterType;

ItkImageType::Pointer applyHistogramEqualization(std::string inputImageName, int radius);

#endif

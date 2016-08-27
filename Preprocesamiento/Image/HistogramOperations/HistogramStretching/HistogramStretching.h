#ifndef HISTOGRAMSTRETCHING_H
#define HISTOGRAMSTRETCHING_H

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"

typedef itk::Image< unsigned char, 2 >   ItkImageType;
typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;

struct minMax
{
  int minimum;
  int maximum;
};

minMax findMinAndMaxValues(ItkImageType::Pointer img);
ItkImageType::Pointer applyStretchingToTheImage(ItkImageType::Pointer img, minMax minmax);

#endif

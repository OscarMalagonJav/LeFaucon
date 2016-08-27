#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkBinomialBlurImageFilter.h"

typedef itk::Image<unsigned char, 2 > ItkImageType;
typedef itk::ImageFileReader<ItkImageType> ItkFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ItkFileWriterType;//Change the output image by ItkImageFloatType
typedef itk::BinomialBlurImageFilter<ItkImageType, ItkImageType> smoothingFilterType; //Change the output image by ItkImageFloatType

ItkImageType::Pointer applyNoiseBinomialBlur(std::string inputImageName, int repetitions);

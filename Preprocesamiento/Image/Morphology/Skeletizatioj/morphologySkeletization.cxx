#include "itkImage.h"
#include "itkBinaryThinningImageFilter.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkRescaleIntensityImageFilter.h"

  typedef itk::Image< unsigned char, 2 >   ItkImageType;
  typedef itk::ImageFileReader< ItkImageType >  ImageFileReaderType;
  typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;
  typedef itk::RescaleIntensityImageFilter< ItkImageType, ItkImageType > RescaleFilterType;
  typedef itk::BinaryThinningImageFilter<ItkImageType, ItkImageType> BinaryThinningImageFilterType; 

int main(int argc, char * argv[])
{
  
  
  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName( inputImageName.c_str() );
  reader->Update();

  BinaryThinningImageFilterType::Pointer binaryThinningImageFilter = BinaryThinningImageFilterType::New(); 
  binaryThinningImageFilter->SetInput(reader->GetOutput());
  binaryThinningImageFilter->Update();

  RescaleFilterType::Pointer rescaler= RescaleFilterType::New();
  rescaler->SetInput(binaryThinningImageFilter->GetOutput());
  rescaler->SetOutputMinimum(0);
  rescaler->SetOutputMaximum(255);
  rescaler->Update();

  ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
  writer->SetFileName(outputImageName);
  writer->SetInput(rescaler->GetOutput());
  //writer->SetInput(ItkResultImage);
  writer->Update();
  return EXIT_SUCCESS;
 
} 

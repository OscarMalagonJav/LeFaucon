#include "ImageConvolution.h"

void CreateKernel(ItkFloatImageType::Pointer kernel, int width, float kernelValues[])
{
  ItkFloatImageType::IndexType start;
  start.Fill(0);
  ItkFloatImageType::SizeType size;
  size.Fill(width);
  ItkFloatImageType::RegionType region;
  region.SetSize(size);
  region.SetIndex(start);
  kernel->SetRegions(region);
  kernel->Allocate();
    int indexArray =0;
    ItkFloatImageType::SizeType regionSize = region.GetSize();
    for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
      {
          for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
          {
            ItkFloatImageType::IndexType pixelIndex;
            pixelIndex[0] = rowIndex;
            pixelIndex[1] = columnIndex;
      	    kernel->SetPixel(pixelIndex,(float)kernelValues[indexArray]);
            indexArray++;
          }
      }
}

UnsignedCharImageType::Pointer convolveImage(std::string inputImage, int width, float kernelValues[]){
  ItkFloatImageType::Pointer kernel = ItkFloatImageType::New();
  CreateKernel(kernel, width, kernelValues);
  ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
  reader->SetFileName(inputImage);
  ConvolveItkFloatImageType::Pointer convolutionFilter = ConvolveItkFloatImageType::New();
  convolutionFilter->SetInput(reader->GetOutput());
  #if ITK_VERSION_MAJOR >= 4
  convolutionFilter->SetKernelImage(kernel);
  #else
  convolutionFilter->SetImageKernelInput(kernel);
  #endif
  CastFilterType::Pointer castFilter = CastFilterType::New();
  castFilter->SetInput(convolutionFilter->GetOutput());
  std::cout << "result" <<castFilter->GetOutput()<< std::endl;
  castFilter->Update();

  return castFilter->GetOutput();
}

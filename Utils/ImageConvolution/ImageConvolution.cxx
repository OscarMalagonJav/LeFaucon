#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkConvolutionImageFilter.h"
#include "itkImageFileWriter.h"

typedef itk::Image<float, 2> ItkImageType;
typedef itk::ImageFileReader<ItkImageType>        ImageFileReaderType;
typedef itk::ConvolutionImageFilter<ItkImageType> ConvolveItkImageType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;

  void CreateKernel(ItkImageType::Pointer kernel, int width, float kernelValues[])
  {
    ItkImageType::IndexType start;
    start.Fill(0);

    ItkImageType::SizeType size;
    size.Fill(width);

    ItkImageType::RegionType region;
    region.SetSize(size);
    region.SetIndex(start);

    kernel->SetRegions(region);
    kernel->Allocate();

      int indexArray =0;
      ItkImageType::SizeType regionSize = region.GetSize();
      for(unsigned int rowIndex = 0; rowIndex < regionSize[0]; rowIndex++)
        {
            for(unsigned int columnIndex = 0; columnIndex < regionSize[1]; columnIndex++)
            {
              ItkImageType::IndexType pixelIndex;
              pixelIndex[0] = rowIndex;
              pixelIndex[1] = columnIndex;
        	    kernel->SetPixel(pixelIndex,(float)kernelValues[indexArray]);
         	    indexArray++;
            }
        }
  }

  std::string showParametersInfo(int argc, char * argv[])
  {
    std::string execute= "";
    std::cout<<"Parameters"<<std::endl;
    std::cout<< "Input image name: "<< argv[1] <<std::endl;
    std::cout<< "Output image name: "<< argv[2] <<std::endl;
    std::cout<< "Kernel size.........: "<< argv[3]<<"x"<<argv[3]<<std::endl;
    for(int i=0; i<argc-4; i++)
    {
    	std::cout<<"Kernel\'s value   "<<i<<"...."<<argv[i+4]<<std::endl;
    }
    std::cout<<"*********************************************"<<std::endl;
    std::cout<<"Continue?...(Y/N)"<<std::endl;
    std::cin>>execute;
    return execute;
  }

  int main(int argc, char * argv[])
  {
    // Verify command line arguments
    if( argc < 2 )
      {
      std::cerr << "Usage: ";
      std::cerr << argv[0] << "inputImage outputImage kernelSize value0 value1 ... valueN" << std::endl;
      return EXIT_FAILURE;
      }
    std::string execute = showParametersInfo(argc, argv);
    if(execute=="y" || execute=="Y"){
      int  width = atoi(argv[3]);
      float kernelValues[argc-2];
      for(int i=0; i<argc-4; i++)
      {
    	   kernelValues[i] = atof(argv[i+4]);
      }
        ItkImageType::Pointer kernel = ItkImageType::New();
        CreateKernel(kernel, width, kernelValues);
        ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
        reader->SetFileName( argv[1] );
        ConvolveItkImageType::Pointer convolutionFilter = ConvolveItkImageType::New();
        convolutionFilter->SetInput(reader->GetOutput());
        #if ITK_VERSION_MAJOR >= 4
        convolutionFilter->SetKernelImage(kernel);
        #else
        convolutionFilter->SetImageKernelInput(kernel);
        #endif
        ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
        writer->SetFileName(argv[2]);
        writer->SetInput(convolutionFilter->GetOutput());
        writer->Update();
        return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}

#include "ImageConvolution.h"
#include "../ShowParameters/showParameters.h"

int main(int argc, char * argv[])
{
  // Verify command line arguments
  if( argc < 2 )
    {
    std::cerr << "Usage: ";
    std::cerr << argv[0] << "inputImage outputImage kernelSize value0 value1 ... valueN" << std::endl;
    return EXIT_FAILURE;
    }
  std::map<std::string, std::string> info;
  std::map<std::string,std::string>::iterator it = info.begin();
  info.insert(it, std::pair<std::string,std::string>("InputImage", argv[1]));
  info.insert(it, std::pair<std::string,std::string>("OutputImage", argv[2]));
  float kernelValues[argc-2];
  int  width = atoi(argv[3]);
  for(int i=0; i<argc-4; i++)
  {
     kernelValues[i] = atof(argv[i+4]);
     //info.insert(it, std::pair<std::string,std::string>("Kernel value " << i, kernelValues[i]<<""));
  }
  std::string execute = "y";//showParametersInfo(info);
  if(execute=="y" || execute=="Y"){
    UnsignedCharImageType::Pointer resultImage = convolveImage(argv[1],width, kernelValues);
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(argv[2]);
    writer->SetInput(resultImage);
    writer->Update();
    return EXIT_SUCCESS;
}else{
  return EXIT_FAILURE;
}
}

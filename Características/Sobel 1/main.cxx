#include "Sobel.h"

int main(int argc, char * argv[])
{
  
  if( argc < 2 )
    {
    std::cerr << "Uso" << std::endl;
    std::cerr << argv[0] << " imagenEntrada nombreImagenSalida.extension " << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImage = argv[1];
  std::string outputImage = argv[2];
  std::string execute = "y";//showParameters(inputImage,outputImage);
  
  if(execute=="y" || execute=="Y"){
   
    ItkUnsignedCharImageType::Pointer sobel = applySobel(inputImage);
    ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
    writer->SetFileName(outputImage);
    writer->SetInput(sobel);
    writer->Update();

    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
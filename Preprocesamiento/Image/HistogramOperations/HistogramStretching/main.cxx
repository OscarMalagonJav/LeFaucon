#include "HistogramStretching.h"

int main(int argc, char * argv[])
{
  if( argc < 4 )
    {
    std::cerr << "Usage" << std::endl;
    std::cerr << argv[0] << " inputImageName outputImageName.extension maximum" << std::endl;
    return EXIT_FAILURE;
    }

  //Argumentos
  std::string inputImageName = argv[1];
  std::string outputImageName = argv[2];
  std::string execute = "y";//showParametersInfo(inputImageName, outputImageName);
  if(execute=="y" || execute=="Y")
  {
      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      reader->SetFileName( inputImageName);
      reader->Update();
      minMax minmax = findMinAndMaxValues(reader->GetOutput());
      ItkImageType::Pointer ItkResultImage;

      if(minmax.minimum ==0 && minmax.maximum==255)
      {
        std::cout<<"It is not possible to stretch the histogram because it is already stretched"<<std::endl;
        return EXIT_SUCCESS;
      }else{
        ItkResultImage = applyStretchingToTheImage(reader->GetOutput(), minmax);
      }
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      writer->SetFileName(outputImageName);
      writer->SetInput(ItkResultImage);
      writer->Update();
      return EXIT_SUCCESS;

  }else{

    return EXIT_FAILURE;

  }
}

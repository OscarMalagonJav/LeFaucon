#include "AddOperation.h"

int main(int argc, char * argv[])
{
    //Uso: ./Filtro nombreSalida.extension  imgEntrada1 imgEntrada2 ... imgEntradaN
	if(argc<4)
    {
        std::cerr<<"Usage" << argv[0] << " outputImageName.extension inputImage1 inputImage2 ... inputImageN " <<std::endl;
        return EXIT_FAILURE;
    }
	std::string outputImageName = argv[1];
	ImageType::Pointer addedImage = addImages(argc,argv);
	WriterType::Pointer writer = WriterType::New();
    writer->SetFileName(outputImageName);
    writer->SetInput(addedImage);
    writer->Update();
	
	return EXIT_SUCCESS;  
}
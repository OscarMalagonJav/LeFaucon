#include "SubsFilter.h"

int main(int argc, char * argv[])
{
	if(argc<4)
    {
        std::cerr<<"Usage" << argv[0] << " outputImageName.extension inputImage1 inputImage2" <<std::endl;
        return EXIT_FAILURE;
    }

	std::string imgSalida = argv[1];
	ImageType::Pointer substractedImage =  substractImages(argc, argv);
	escritor->SetFileName(imgSalida);
	escritor->SetInput(subtractFilter->GetOutput());
	escritor->Update();
	
	return EXIT_SUCCESS;
}
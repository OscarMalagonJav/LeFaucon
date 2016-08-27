#include "SubsFilter.h"

ImageType::Pointer substractImages(int argc, char * argv[])
{
	ImageType::Pointer image1 = ImageType::New();
	ImageType::Pointer image2 = ImageType::New();
	ReaderType::Pointer lector = ReaderType::New();
	WriterType::Pointer escritor = WriterType::New();

	std::string img1 = argv[2];
	std::string img2 = argv[3];

	lector->SetFileName(img1.c_str());
	lector->Update();
	image1 = lector->GetOutput();

	lector->SetFileName(img2.c_str());
	lector->Update();
	image2 = lector->GetOutput();

	SubtractImageFilterType::Pointer subtractFilter = SubtractImageFilterType::New();
	subtractFilter->SetInput1(image1);
	subtractFilter->SetInput2(image2);
	subtractFilter->Update();
	return subtractFilter->GetOutput();
}
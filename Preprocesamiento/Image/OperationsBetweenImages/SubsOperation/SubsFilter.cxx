#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImage.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkSubtractImageFilter.h"
#include <typeinfo>

typedef itk::Image<unsigned char, 2>  ImageType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::SubtractImageFilter <ImageType, ImageType, ImageType >SubtractImageFilterType;
int main(int argc, char * argv[])
{
	//Uso: ./Filtro nombreSalida.extension  imgEntrada1 imgEntrada2 ... imgEntradaN \0
	ImageType::Pointer image1 = ImageType::New();
	ImageType::Pointer image2 = ImageType::New();
	ReaderType::Pointer lector = ReaderType::New();
	WriterType::Pointer escritor = WriterType::New();

	std::string img1 = argv[2];
	std::string img2 = argv[3];
	std::string imgSalida = argv[1];

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
	escritor->SetFileName(imgSalida);
	escritor->SetInput(subtractFilter->GetOutput());
	escritor->Update();
	
	return EXIT_SUCCESS;
}


#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkSobelEdgeDetectionImageFilter.h"
#include <typeinfo>
int main(int argc, char * argv[])
{
  
  if( argc < 2 )
    {
    std::cerr << "Uso" << std::endl;
    std::cerr << argv[0] << " imagenEntrada nombreImagenSalida.extension " << std::endl;
    return EXIT_FAILURE;
    }

  std::string nombreIEntrada = argv[1];
  std::string nombreISalida = argv[2];

  std::string seguir= "";
  std::cout<<"Parámetros"<<std::endl;
  std::cout<< "Imagen de entrada: "<< nombreIEntrada <<std::endl;
  std::cout<< "Imagen de salida.: "<< nombreISalida <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continuar?...(Y/N)"<<std::endl;
  std::cin>>seguir;
  if(seguir=="y" || seguir=="Y"){
    typedef itk::Image<unsigned char, 2 > imagenItk;
    typedef itk::Image<float, 2 > imagenItkFloat;    
    typedef itk::ImageFileReader<imagenItkFloat> lector;
    typedef itk::ImageFileWriter<imagenItkFloat> escritor;//Cambiar la imagen de salida por imagenItkFloat
    typedef itk::SobelEdgeDetectionImageFilter<imagenItkFloat, imagenItkFloat> sobel; //Cambiar la imagen de salida por imagenItkFloat

    //Segun la documentacion es mejor dejar la imagen de salida como float, sin embargo
    //para este caso se dejó como entero para poder ver el resultado en una imagen de tipo PNG
    lector::Pointer l = lector::New();
    l->SetFileName(nombreIEntrada);
    sobel::Pointer filtroSobel = sobel::New();
    filtroSobel->SetInput( l->GetOutput() );
    
    imagenItkFloat::Pointer imgResultado = filtroSobel->GetOutput();
    /*escritor::Pointer esc = escritor::New();
    esc->SetFileName(nombreISalida);
    esc->SetInput(imgResultado);
    esc->Update();*/

    //Deberia ser mas sencillo ver el resultado con VTK
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}
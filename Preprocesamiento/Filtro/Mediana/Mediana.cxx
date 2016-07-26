#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkMedianImageFilter.h"
#include <typeinfo>
int main(int argc, char * argv[])
{
  
  if( argc < 2 )
    {
    std::cerr << "Uso" << std::endl;
    std::cerr << argv[0] << " imagenEntrada nombreImagenSalida.extension radio" << std::endl;
    return EXIT_FAILURE;
    }

  std::string nombreIEntrada = argv[1];
  std::string nombreISalida = argv[2];
  int radio = atoi(argv[3]);

  std::string seguir= "";
  std::cout<<"Parámetros"<<std::endl;
  std::cout<< "Imagen de entrada: "<< nombreIEntrada <<std::endl;
  std::cout<< "Imagen de salida.: "<< nombreISalida <<std::endl;
  std::cout<< "Radio.........: "<< radio <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continuar?...(Y/N)"<<std::endl;
  std::cin>>seguir;
  if(seguir=="y" || seguir=="Y"){
    typedef itk::Image<unsigned char, 2 > imagenItk;
    typedef itk::ImageFileReader<imagenItk> lector;
    typedef itk::ImageFileWriter<imagenItk> escritor;
    typedef itk::MedianImageFilter<imagenItk, imagenItk > filtroMediana;

    lector::Pointer l = lector::New();
    l->SetFileName(nombreIEntrada);
    filtroMediana::Pointer mediana = filtroMediana::New();
    filtroMediana::InputSizeType rad;
    rad.Fill(radio);
    mediana->SetRadius(rad);
    mediana->SetInput( l->GetOutput() );

    imagenItk::Pointer imgResultado = mediana->GetOutput();
    escritor::Pointer esc = escritor::New();
    esc->SetFileName(nombreISalida);
    esc->SetInput(imgResultado);
    esc->Update();
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}
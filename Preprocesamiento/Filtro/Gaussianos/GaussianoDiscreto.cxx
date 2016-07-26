#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkDiscreteGaussianImageFilter.h"
#include <typeinfo>
int main(int argc, char * argv[])
{
  
  if( argc < 2 )
    {
    std::cerr << "Uso" << std::endl;
    std::cerr << argv[0] << " imagenEntrada nombreImagenSalida.extension varianza" << std::endl;
    return EXIT_FAILURE;
    }

  std::string nombreIEntrada = argv[1];
  std::string nombreISalida = argv[2];
  double varianza = atof(argv[3]);

  std::string seguir= "";
  std::cout<<"Parámetros"<<std::endl;
  std::cout<< "Imagen de entrada: "<< nombreIEntrada <<std::endl;
  std::cout<< "Imagen de salida.: "<< nombreISalida <<std::endl;
  std::cout<< "Varianza.........: "<< varianza <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continuar?...(Y/N)"<<std::endl;
  std::cin>>seguir;
  if(seguir=="y" || seguir=="Y"){
    typedef itk::Image<unsigned char, 2 > imagenItk;
    //typedef itk::Image<float, 2 > imagenItkFloat;    
    typedef itk::ImageFileReader<imagenItk> lector;
    typedef itk::ImageFileWriter<imagenItk> escritor;//Cambiar la imagen de salida por imagenItkFloat
    typedef itk::DiscreteGaussianImageFilter<imagenItk, imagenItk> filtroGaussianoDiscreto; //Cambiar la imagen de salida por imagenItkFloat

    //Segun la documentacion es mejor dejar la imagen de salida como float, sin embargo
    //para este caso se dejó como entero para poder ver el resultado en una imagen de tipo PNG
    lector::Pointer l = lector::New();
    l->SetFileName(nombreIEntrada);
    filtroGaussianoDiscreto::Pointer gaussiano = filtroGaussianoDiscreto::New();
    gaussiano->SetInput( l->GetOutput() );
    gaussiano->SetVariance(varianza);
    imagenItk::Pointer imgResultado = gaussiano->GetOutput();
    escritor::Pointer esc = escritor::New();
    esc->SetFileName(nombreISalida);
    esc->SetInput(imgResultado);
    esc->Update();
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}
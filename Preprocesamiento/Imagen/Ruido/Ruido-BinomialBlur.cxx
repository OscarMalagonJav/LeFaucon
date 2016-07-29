#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkBinomialBlurImageFilter.h"
#include <typeinfo>
int main(int argc, char * argv[])
{
  
  if( argc < 3 )
    {
    std::cerr << "Uso" << std::endl;
    std::cerr << argv[0] << " imagenEntrada nombreImagenSalida.extension numeroRepeticiones" << std::endl;
    return EXIT_FAILURE;
    }

  std::string nombreIEntrada = argv[1];
  std::string nombreISalida = argv[2];
  int repeticiones = atoi(argv[3]);

  std::string seguir= "";
  std::cout<<"Parámetros"<<std::endl;
  std::cout<< "Imagen de entrada: "<< nombreIEntrada <<std::endl;
  std::cout<< "Imagen de salida.: "<< nombreISalida <<std::endl;
  std::cout<< "Numero de repeticiones: "<< repeticiones <<std::endl
  <<"*********************************************"<<std::endl;
  std::cout<<"Continuar?...(Y/N)"<<std::endl;
  std::cin>>seguir;
  if(seguir=="y" || seguir=="Y"){
    typedef itk::Image<unsigned char, 2 > imagenItk;    
    typedef itk::ImageFileReader<imagenItk> lector;
    typedef itk::ImageFileWriter<imagenItk> escritor;//Cambiar la imagen de salida por imagenItkFloat
    typedef itk::BinomialBlurImageFilter<imagenItk, imagenItk> smoothingFilter; //Cambiar la imagen de salida por imagenItkFloat

    lector::Pointer l = lector::New();
    l->SetFileName(nombreIEntrada);
    smoothingFilter::Pointer filtroReduccionRuido = smoothingFilter::New();
    filtroReduccionRuido->SetInput( l->GetOutput() );
    filtroReduccionRuido->SetRepetitions( repeticiones);
    
    imagenItk::Pointer imgResultado = filtroReduccionRuido->GetOutput();
    escritor::Pointer esc = escritor::New();
    esc->SetFileName(nombreISalida);
    esc->SetInput(imgResultado);
    esc->Update();

    //Deberia ser mas sencillo ver el resultado con VTK
    return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }

}
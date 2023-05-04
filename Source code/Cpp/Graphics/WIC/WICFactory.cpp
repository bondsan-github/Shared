#include "Graphics/WICFactory.hpp"

WICFactory::WICFactory()
{
    if( not wic_factory )
    {
        CoCreateInstance( CLSID_WICImagingFactory2 ,
                          nullptr ,
                          CLSCTX_INPROC_SERVER ,
                          IID_PPV_ARGS( & wic_factory ) ) >> result_check;
    }
}

WICFactory::~WICFactory()
{
    wic_factory.Reset();
}
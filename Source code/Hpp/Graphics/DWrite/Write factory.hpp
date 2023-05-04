#pragma once

#include <wrl/client.h>
#include <dwrite.h>

#include "Logging.hpp"

namespace hid
{
    class write_factory
    {
        protected:

            Microsoft::WRL::ComPtr<IDWriteFactory> factory_write {};

        public:

            write_factory()
            {
                DWriteCreateFactory( DWRITE_FACTORY_TYPE_SHARED ,
                                     __uuidof( IDWriteFactory ) ,
                                     & factory_write ) >> result_check;
            }

            ~write_factory()
            {
                if( factory_write ) { factory_write->Release(); }
            }
    };
}

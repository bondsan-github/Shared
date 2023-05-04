#pragma once

#include "..\headers\hid_device.h"

#include "..\headers\hid_globals.h"
#include "..\headers\write_d2d.h"

//#include <windows.h> // RAWINPUTDEVICELIST
#include <vector>

namespace hid
{
    class hid_devices // public write
    {
        private:
            
            std::vector< RAWINPUTDEVICELIST > raw_device_list {};
            std::vector< hid_device >         input_devices   {};

            text_d2d information {};

        public:

            void initialise();
            
            hid_device * get_device( HANDLE in_handle );
            //add_contact( device, identifier );
            //update_contact_x( device, identifier, x);
            //update_contact_x( device, identifier, y);

            //void update_devices( RAWINPUT * in_hid_report , uint in_buffer_size );
            void update_devices( RAWINPUT * in_hid_report );
            
            void update_devices_buffered( RAWINPUT ** in_raw_input_buffer, uint in_buffer_size );
            void update_device_buffered( RAWINPUT ** in_raw_input_buffer, uint in_buffer_size );

            void draw();
    };
}
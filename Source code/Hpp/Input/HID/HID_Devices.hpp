#pragma once

#include "Source code/Hpp/Input/HID/HID_Globals.hpp"
#include "Source code/Hpp/Input/HID/HID_Device.hpp"

#include "Source code/Hpp/Graphics/DWrite/Text.hpp"

#include "Source code/Hpp/Output/Logging.hpp"

//#include <windows.h> // RAWINPUTDEVICELIST
#include <vector>

namespace HID
{
    class Multiple_touch;

    class Devices : public Logging
    {
        private:
            
            std::vector< RAWINPUTDEVICELIST > raw_device_list {};
            std::vector< Device >             input_devices   {};

            Text information {};

            Multiple_touch & application;

        public:

            Devices( Multiple_touch & application );

            void initialise();
            
            Device * get_device( HANDLE in_handle );
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
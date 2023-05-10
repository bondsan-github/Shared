#pragma once

#include "Source code/Hpp/Custom types.hpp"
#include "Source code/Hpp/Graphics/Size.hpp"
#include "Source code/Hpp/Graphics/DWrite/Text.hpp"
#include "Source code/Hpp/Input/HID/HID_Globals.hpp"
#include "Source code/Hpp/Input/HID/HID_Button.hpp"
#include "Source code/Hpp/Input/HID/HID_Value.hpp"

#include <string>
#include <vector>
#include <hidpi.h>

namespace HID
{
    class Device;

    class Collection : public _HIDP_LINK_COLLECTION_NODE
    {
        private:

            Device * device { nullptr };

            Text information {};
            //float font_size{ 15.0f };
            //D2D1::ColorF font_colour { D2D1::ColorF::Yellow };
            //D2D1_SIZE_F layout_size { 200.0f, 80.0f };
            
            std::vector< Button > input_buttons{};
            std::vector< Value >  input_values{};

            std::vector< Button > output_buttons{};
            std::vector< Value >  output_values{};

            std::vector< Button > feature_buttons{};
            std::vector< Value >  feature_values{};

            Size information_spacing { 15.0f, 15.0f }; // spacers

        public:

            Collection() {}
            Collection( Device * in_device ) : device( in_device ) {}
            void operator = ( const _HIDP_LINK_COLLECTION_NODE & in_node );
            void operator = ( _HIDP_LINK_COLLECTION_NODE && in_node ) noexcept;

            void set_item_positions();

            void add_button( item_type in_type , Button & in_button );
            void add_value( item_type in_type , Value & in_value );

            void set_information_text();
            void set_text_position( Point const & in_position );
            
            Point position() const { return information.position(); }
            float height()   const { return information.height();  }
            float right()    const { return information.right(); }
            float bottom()   const { return information.bottom(); }
            float top()      const { return information.top(); }

            Range range( const ushort & in_page ,
                         const ushort & in_usage ,
                         const Report_type & in_report_type ,
                         const Value_type & in_value_type );
            //std::vector<hid_button>::iterator get_input_buttons() { return input_buttons.begin(); }
            //uint get_contact_amount();
            //uint get_contact_identifier();
            //uint get_x();
            //uint get_y();
            
            void update( RAWINPUT * in_raw_data );
            //void update( RAWHID in_raw_data );
            void draw() const;
    };
}
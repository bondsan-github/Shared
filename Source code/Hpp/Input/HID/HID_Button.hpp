#pragma once

#include "Source code/Hpp/Custom types.hpp"
#include "Source code/Hpp/Graphics/DWrite/Text.hpp"

#include <hidpi.h>

namespace HID
{
    class Device;

    class Button : public _HIDP_BUTTON_CAPS
    {
        private:

            bool on { false };

            Text         information;
            std::wstring content{};
            Device *     device {}; // TODO: change to shared/unique_ptr<>

            //_HIDP_BUTTON_CAPS capabilities {};

        public:

            Button( Device * in_device, _HIDP_BUTTON_CAPS const & in_button_capabilities );
            
            void text();
            void append_text( std::wstring in_text ) { information.add(in_text); }
            void position(const Point & in_position ) { information.position(in_position); }
            void layout_size( const D2D1_SIZE_F & in_size ) { information.layout_size( in_size ); }

            Point position() const { return information.position(); }

            float top() const { return information.top(); }
            float right() const { return information.right(); }
            float width() const { return information.width();  }
            float height() const { return information.height(); }
            
            void update( RAWINPUT * in_raw_data );
            void update_information();

            //void update( RAWHID in_raw_data );

            void draw() { information.draw(); }

            /*
            ushort get_bit_field()               const { return BitField;       }
            bool   get_is_absolute()             const { return IsAbsolute;     } // or relative
            ushort get_origin_usage()            const { return origin_usage;    }
            ushort get_origin_page()             const { return origin_page;     }
            bool   get_is_range()                const { return is_range;        }
            hid_range  get_usages_range()            const { return usages;          }
            ushort  get_usage()            const { return usages;          }
            ushort get_data_identifier()         const { return data_identifier; }
            hid_range  get_data_identifiers()        const { return data_identifiers; }
            bool   get_has_strings()             const { return has_strings;     }
            ushort get_string_index()            const { return string;          } // HidD_GetIndexedString        
            hid_range  get_strings_range()           const { return strings;         }
            long   get_strings_index_begin()     const { return strings.begin; }
            long   get_strings_index_end()       const { return strings.end;   }
            bool   get_has_designators()         const { return has_designators; }
            ushort get_designator()              const { return designator;      } // describes body part recommended control. Index points to a designator in the Physical descriptor
            hid_range  get_designators_range()       const { return designators;     }
            long   get_designators_range_begin() const { return designators.begin;   }
            long   get_designators_range_end()   const { return designators.end;     }*/
    };
}
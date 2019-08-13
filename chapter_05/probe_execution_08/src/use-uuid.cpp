// File: use-uuid.cpp
//
#include <cstdlib>
#include <iostream>
#include <string>
#include <uuid/uuid.h>

int main() {
   uuid_t uuid;

   uuid_generate(uuid);
   char uuid_str[37];
   uuid_unparse_lower(uuid, uuid_str);
   std::cout << "Generate UUID = " << uuid_str << std::endl;

   // parse (from string)
   uuid_t uuid2;
   uuid_parse(uuid_str, uuid2);
   int retval;
   retval = uuid_compare(uuid, uuid2);
   std::cout << "uuid_compare() result = " << retval << std::endl;

   // compare (retval == 1)
   uuid_t uuid3;
   uuid_parse("1b4e28ba-2fa1-11d2-883f-0016d3cca427", uuid3);
   retval = uuid_compare(uuid, uuid3);
   std::cout << "uuid_compare(0 result = " << retval << std::endl;

   // is null? (retval == 0)
   retval = uuid_is_null(uuid);
   std::cout << "uuid_null() result = " << retval << std::endl;

   // is null? (retval == 1)
   uuid_clear(uuid);
   retval = uuid_is_null(uuid);
   std::cout << "uuid_null() result = " << retval << std::endl;

   return EXIT_SUCCESS;
}


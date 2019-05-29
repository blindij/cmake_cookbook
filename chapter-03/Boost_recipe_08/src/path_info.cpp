// File: path_info.cpp
//
// Example from the filesystem library provided by Boost.
// Being a cross-platform library it abstracts the differences
// between filesystems on different operating systems into
// a coherent, highlevel API.
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

const char *say_what(bool b) { return b ? "true" : "false"; }

int main(int argc, char *argv[]){
   if (argc < 2) {
      cout 
         << "Usage: path_info path-element [path-element...]\n"
              "Compose a path via operator/= from one or more path-element arguments\n"
              "Example: path_info foo/bar baz\n"
#ifdef BOOST_POSIX_API
              " would report info about the composed path foo/bar/baz\n";
#else // BOOST_WINDOWS_API
              " would report info about the composed path foo/bar\\baz\n";
#endif
      return 1;
   }
  
   path p;
   for (; argc > 1; --argc, ++argv) p /= argv[1];  // compose path p 
                                                   // command line args
   cout << "\ncomposed path:\n";
   cout << " operator<<()-----------: " << p << "\n";
   cout << " make_preferred()-------: " << p.make_preferred() << "\n";

   cout << "\nelements:\n";
   for (auto element : p)
      cout << " " << element << '\n';

   cout << "\nobservers, native format:" << endl;
#ifdef BOOST_POSIX_API
   cout << " native()-------------: " << p.native() << endl;
   cout << " c_str()--------------: " << p.c_str()  << endl;
#else // BOOST_WINDOWS_API
   wcout << L" native()-------------: " << p.native() << endl;
   wcout << L" c_str()--------------: " << p.c_str()  << endl;
#endif
   cout << " string()-------------: " << p.native() << endl;
   wcout << L" c_str()------------: " << p.c_str() << endl;

   cout << "\nobservers, generic format:\n";
   cout << " generic_string()------: " << p.generic_string() << endl;
   wcout << L" generic_wstring()------: " << p.generic_wstring() << endl;

   cout << "\ndecomposition:\n";
   cout << " root_name()---------------: " << p.root_name() << endl;
   cout << " root_directory()----------: " << p.root_directory() << endl;
   cout << " root_path()---------------: " << p.root_path() << endl;
   cout << " relative_path()-----------: " << p.relative_path() << endl;
   cout << " parent_path()-------------: " << p.parent_path() << endl;
   cout << " filename()----------------: " << p.filename() << endl;
   cout << " stem()--------------------: " << p.extension() << endl;

   cout << "\nquery\n";
   cout << " empty()-------------------: " << say_what(p.empty()) << '\n';
   cout << " is_absolute()-------------: " << say_what(p.is_absolute()) << '\n';
   cout << " has_root_name()-----------: " << say_what(p.has_root_name()) << '\n';
   cout << " has_root_directory()------: " << say_what(p.has_root_directory()) << '\n';
   cout << " has_root_path()-----------: " << say_what(p.has_root_path()) << '\n';
   cout << " has_relative_path()-------: " << say_what(p.has_relative_path()) << '\n';
   cout << " has_parent_path()---------: " << say_what(p.has_parent_path()) << '\n';
   cout << " has_filename()------------: " << say_what(p.has_filename()) << '\n';
   cout << " has_stem()----------------: " << say_what(p.has_stem()) << '\n';
   cout << " has_extension-------------: " << say_what(p.has_extension()) << '\n';

   return 0;
}

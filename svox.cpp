/*

C++ wrapper over SVOX - pico2wave

Copyright (C) 2015 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 2910 $ $Date:: 2015-12-06 #$ $Author: serge $


#include "svox.h"             // self

#include <sstream>            // std::ostringstream
//#include <iostream>           // std::cout    // DEBUG
#include <cstdlib>            // system

namespace svox
{


bool Svox::say( const std::string & text, const std::string & filename, const std::string & lang, std::string & error )
{
    std::ostringstream s;

    s <<
        "#/bin/bash \n" <<
        "pico2wave -w " << filename << " -l " << lang << " \"" << text << "\"";

    //std::cout << "executing: " << s.str() << std::endl;   // DEBUG

    int ret = system( s.str().c_str() );

    if( WEXITSTATUS(ret) == 0 )
    {
        return true;
    }
    else if( WEXITSTATUS(ret) == 127 )
    {
        error = "cannot find pico2wave";
        return false;
    }
    else if( WEXITSTATUS(ret) == 1 )
    {
        error = "invalid parameters";
        return false;
    }

    error = "unknown";
    return false;
}


}   // namespace

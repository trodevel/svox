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

// $Revision: 2909 $ $Date:: 2015-12-06 #$ $Author: serge $

#ifndef SVOX_SVOX_H
#define SVOX_SVOX_H

#include <string>

namespace svox
{

class Svox
{
public:

    bool say( const std::string & text, const std::string & filename, const std::string & lang, std::string & error );
};

} // namespace svox

#endif  // SVOX_SVOX_H

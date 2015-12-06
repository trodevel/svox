#include <iostream>         // cout
#include <map>              // std::map

#include "svox.h"           // svox

int main()
{
    std::map<std::string, std::string> texts =
    {
            { "en-GB",  "hello world" },
            { "en-US",  "hello world" },
            { "de-DE",  "hallo welt" },
            { "ru-RU",  "привет мир" },
            { "fr-FR",  "Bonjour le monde" },
            { "es-ES",  "Hola Mundo" },
            { "it-IT",  "Ciao mondo" },
    };

    svox::Svox g;

    std::string error;

    for( auto & s : texts )
    {
        bool b = g.say( s.second, "test_" + s.first + ".wav", s.first, error );

        if( b == false )
            std::cout << "ERROR: failed to generate text for lang '" << s.first
            << "', error " << error << std::endl;
        else
            std::cout << "OK: generated for '" << s.first << "'" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
//#include <Edit.h>

//check for arg - samla in och radera .out & .txt
//file stream - read from text och dela i vector. 
//dela flagor och parametrar 

// --test=blabla

int main(int argc, char* argv[])
    
{
    //check arguments
    std::vector<std::string> args {argv, argv + argc};
    
    std::vector<std::string> arguments {args.size()};
    
    std::copy(args.begin(), args.end(), arguments.begin());

    arguments.erase(arguments.begin(), arguments.begin()+2);

    // arguments.resize(1);

    std::vector<std::string> flags{};
    std::vector<std::string> parameter{};  
    
    std::for_each(arguments.begin(), arguments.end(), [&flags, &parameter](std::string s)
		  {

		      int first = s.find("--");
		      int seconde = s.find("=");
		      
		      std::string flag_str = s.substr(first+2, seconde-first-2);
		      
		      flags.push_back(flag_str);

		      std::string parameter_str = s.substr(seconde+1,
							   s.length() - flag_str.length() -2);
		      parameter.push_back(parameter_str);
		        
		  });


	for ( auto c : flags)
	{
	    std::cout << c << std::endl; 
	}

	std::cout << "Parametrar: " << std::endl;
	
	for ( auto c : parameter)
	{
	    std::cout << c << std::endl;
	}
	
    // for (int i = 0; i < argc-2; ++i)
    // std::cout << arguments[i] << std::endl;
    
    //read textfile
    std::ifstream file(argv[1]);
    std::vector<std::string> text;

    std::string str{};
    
    while(file >> str)
    {
        text.push_back(str);
    }
    file.close();

    for(auto i : text)
    {
	std::cout << i << std::endl;
    }

    // text.txt --print --substitute=bla+bla --remove=bla

    
    
    
    return 0;
}



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "Edit.h"

void run_flags()
{
    
}
    

int main(int argc, char* argv[])
{
    
    Edit obj;

    std::vector<std::string> arguments {};
    arguments = obj.get_arguments(argc, argv);

    std::cout << "Test args: " << std::endl;
    std::for_each(arguments.begin(), arguments.end(), [](std::string s)
                                                      {
                                                          std::cout<< s << std::endl;
                                                      });
    
    filtered_arguments new_args{obj.filter_arguments(arguments)};
    std::cout << "Test flags & param" << std::endl;

    for ( auto c : new_args.flags)
    {
        std::cout << c << std::endl; 
    }

    std::cout << "Parametrar: " << std::endl;
  
    for ( auto c : new_args.parameters)
    {
        std::cout << c << std::endl;
    }
	
  
    std::ifstream file{};
    std::vector<std::string> text;
        
    obj.open_file(argv[1], file);
        
    text = obj.convert_text(file);
    
    file.close();
                                                                          
    obj.print(text);
    obj.frequency(text);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    obj.table(text);

    // std::vector<std::string> new_text{obj.substitute(new_args, text)};
    text = obj.substitute(new_args, text);
    obj.print(text);
    
    text = obj.remove(new_args, text);
    obj.print(text);
    
    return 0;
}



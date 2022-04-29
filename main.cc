#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "Edit.h"

void run_flags(Edit obj, std::vector<std::string> text, filtered_arguments new_args)
{
    for ( auto c : new_args.flags )
    {
	if (c == "--print")
	{
	    std::cout << "Text:" << "\n";
	    obj.print(text);
	}

	else if (c == "--table")
	{
	    std::cout << "Table:" << "\n";
	    obj.table(text);
        }

	else if (c == "--frequency")
	{
	    std::cout << "Frequency:" << "\n";
	    obj.frequency(text);
	}
	
	else if (c == "--substitute")
	{
	    std::cout << "Text with substituted words:" << "\n";
	    text = obj.substitute(new_args, text);
	    obj.print(text);
	}

        else if (c == "--remove")
	{
	    std::cout << "Text with removed words:" << "\n";
	    text = obj.remove(new_args, text);
	    obj.print(text);
	}

	else
	{
	    throw std::invalid_argument("Invalid argument(s)");
   	}
    }
}

void check_args(int argc, Edit obj, std::vector<std::string> text, filtered_arguments new_args)
{
    if (argc == 2)
    {
	std::cout << "ERROR: Missing arguments. \n"
		     "Usage: ./a.out filename.txt --flag \n"
		     "Flags: print, frequency, table, substitute<old>+<new>, remove<word>"
		  << std::endl;
    }

    else if (argc > 2 && argc < 8)
    {
	run_flags(obj, text, new_args);
    }

    else if (argc > 7)
    {
	throw std::invalid_argument("ERROR: Too many arguments.");
	//std::cout << "ERROR: Too many arguments." << std::endl;
    }
    
}

int main(int argc, char* argv[])
{
    
    Edit obj;
    std::vector<std::string> arguments {};
    std::ifstream file{};
    std::vector<std::string> text;

    obj.open_file(argv[1], file);
    text = obj.convert_text(file);
    file.close();
    
    arguments = obj.get_arguments(argc, argv);
    filtered_arguments new_args{obj.filter_arguments(arguments)};

    check_args(argc, obj, text, new_args);
   
    return 0;
}



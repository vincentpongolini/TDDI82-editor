#include "Edit.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

void Edit::open_file(string file_name, ifstream& file)
{

    file.open(file_name); 
    
}

vector<string> Edit::get_arguments(int argc, char* argv[])
{
    vector<string> args {argv, argv + argc};
    vector<string> temp_args {args.size()};

    copy(args.begin(), args.end(), temp_args.begin());
    temp_args.erase(temp_args.begin(), temp_args.begin()+2);

    return temp_args;
}

vector<string> Edit::convert_text(ifstream& file)
{

    vector<string> text{};
    
    for_each(std::istream_iterator<std::string>(file),
             std::istream_iterator<std::string>(), [&text](std::string s)
                                                   {
                                                       text.push_back(s);
                                                   });
    return text; 
}

filtered_arguments Edit::filter_arguments(vector<string> arguments)
{
    filtered_arguments new_args{};

    for_each(arguments.begin(), arguments.end(),
             [&new_args](string s)
             {

                 int first = s.find("--");
                 int second = s.find("=");

                 string flag_str = s.substr(first+2, second-first-2);
                 new_args.flags.push_back(flag_str);
                 
                 string parameter_str = s.substr(second+1, s.length() - flag_str.length() -2);

                 if(!parameter_str.empty())
                     new_args.parameters.push_back(parameter_str);
                 
             });
    
    return new_args;
}

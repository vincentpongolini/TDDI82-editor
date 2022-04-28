#ifndef EDIT_H
#define EDIT_H

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

struct filtered_arguments
{

    std::vector<std::string> flags{};
    std::vector<std::string> parameters{}; 
};

class Edit
{

public:

    void open_file(std::string file_name, std::ifstream& file);
    std::vector<std::string> get_arguments(int argc, char* argv[]);
    std::vector<std::string> convert_text(std::ifstream& file);
    filtered_arguments filter_arguments(std::vector<std::string> arguments);
    
private:
    
};

#endif

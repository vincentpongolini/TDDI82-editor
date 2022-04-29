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

    void print(std::vector<std::string> text);
    void frequency(std::vector<std::string> text);
    void table(std::vector<std::string> text);
    std::vector<std::string> substitute(filtered_arguments filtered_args,
                                        std::vector<std::string> text);
    std::vector<std::string> remove(filtered_arguments filtered_args,
                                    std::vector<std::string> text);
    
private:
    std::string get_largest_word(std::vector<std::string> text);
    std::string word_new{};
    std::string word_old{};
};

#endif

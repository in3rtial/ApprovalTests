#include <string>
#include <vector>
#include <algorithm>

namespace blackbox {

void RegularSort(std::vector<std::string>& input ) {
        std::sort(input.begin(), input.end());
}

void CaseInsensitiveSort(std::vector<std::string>& strs)
{
    std::sort(
        begin(strs),
        end(strs),
        [](const std::string& str1, const std::string& str2){
            return lexicographical_compare(
                begin(str1), end(str1),
                begin(str2), end(str2),
                [](const char& char1, const char& char2) {
                    return tolower(char1) < tolower(char2);
                }
            );
        }
    );
}


void process(std::vector<std::string>& input) {
    RegularSort(input);
    //CaseInsensitiveSort(input);
}

} //namespace blackbox

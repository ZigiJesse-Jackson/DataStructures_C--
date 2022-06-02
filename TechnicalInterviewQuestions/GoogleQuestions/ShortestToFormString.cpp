#include <string>
#include <map>
#include <cstring>

std::map<char, int> map_char_to_pos(const std::string src_string, int len) {
    std::map<char, int> mapped_src_chars;
    //mapping character to its position
    for(int i=0;i<len;i++) {
        // avoiding duplicate char mapping
        if(mapped_src_chars.find(src_string[i])!=mapped_src_chars.end())continue;
        mapped_src_chars[src_string[i]] = i;
    }
    return mapped_src_chars;
}


int short_to_form_string(const std::string src, const std::string target){
    int n = src.length()+1;
    char* src_chars = new char [n];
    int count = 0;

    std::map<char, int> mapped_src = map_char_to_pos(src, src.length());

    for(int i=0;i<target.length();){
        // loop to find substring
        for(int j=0;j<src.length();j++){
            // check if char in target is in src
            if(mapped_src.find(target[i])==mapped_src.end()) return -1;
            else{
                //if current target char matches src char
                if(mapped_src[target[i]] == j) i++; 
            }
        }
        // increments after a substring found
        count++;
    }
    return count;
}


#include <iostream>
#include <string>
#include "TechnicalInterviewQuestions/GoogleQuestions/ShortestToFormString.cpp"
#include <array>

int main()
{   
    std::string src = "xyxz";
    std::string target = "xzyxxz";
    std::cout << short_to_form_string(src, target);
    
    return 0;
}
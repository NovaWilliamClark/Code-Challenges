#include <array>
#include <string>
#include <regex>

std::array<float, 4> ParseQuaternion(std::string t_quaternion)
{
    
   /*
    *  parse the string form of a quaternion (ex."1 + 2i - 3j - 4k")
    *  into a Quaternion Struct of coefficients(ex.[1 2 - 3 - 4]).
    *
    *  The quaternion string can be formatted in many different ways:
    *      standard form: 1+2i-3j-4k
    *      missing terms: 1-3k, 2i-4k
    *      missing coefficients: i+j-k
    *      It may not be in the right order: 2i-1+3k-4j
    *      The coefficients may be integers or decimals: 7-2.4i+3.75j-4.0k
    */
    
    
    // Store regex match Results
    std::smatch matches;
  
    // Lambda function that will locate an imaginary number using a letter as a parameter (ex. "i" will find -2i)).
    // If no value is assigned a signed `1` is returned. If no value is matched `0` is returned
    auto g = [](const std::string& t_letter, const std::string& t_equation, std::smatch& t_matches)
    {
        // Pattern for getting imaginary number coefficient with signage
        const std::regex pattern(R"((-?)([ (0-9).]+)?)" + t_letter);
        std::string result;
      
        // Search for match
        if (std::regex_search(t_equation, t_matches, pattern))
        {
            if (t_matches[2].matched && t_matches[2] != " ")
            {
                // If the match contains a numeric value, remove any spaces, then
                // concatenate the signage to the value;
                auto matchStr = t_matches[2].str();
                matchStr.erase(remove_if(matchStr.begin(), matchStr.end(), isspace), matchStr.end());
                result = t_matches[1].str() + matchStr;
            }
            else
            {
                // If the match does not contains a numeric value,
                // concatenate signage and assume coefficient is 1
                result = t_matches[1].str() + "1";
            }
        }
        else
        {
            // no match value shall be 0.
            result = "0";
        }
        return std::stof(result);
    };
  
    // Pattern for getting the w component with signage (real component)
    std::regex realCompPattern("(-?)([0-9.]+)*[^ijk]([+]|-|$)");
  
    // Search for match
    std::regex_search(t_quaternion, matches, realCompPattern);
  
    // Store real component
    float w;
    if (!matches.empty())
    {
        w = std::stof(matches[0]);
    }
    else
    {
        w = 0;
    }
  
    // retrieve values from Lambda Function
    auto i = g("i", t_quaternion, matches);
    auto j = g("j", t_quaternion, matches);
    auto k = g("k", t_quaternion, matches);

    // store & return the resulting quaternion coeffcients
    std::array<float, 4> values = { w, i, j, k };
  return values;
}

#include <array>
#include <string>
#include <regex>

std::array<float, 4> ParseQuaternion(std::string t_quaternion)
{
  // Parse in a quaternion as 
    std::smatch matches;
  
    auto g = [](const std::string& t_letter, const std::string& t_equation, std::smatch& t_matches) {
        const std::regex pattern(R"((-?)([ (0-9).]+)?)" + t_letter);
        std::string result;
        if (std::regex_search(t_equation, t_matches, pattern))
        {
            if (t_matches[2].matched && t_matches[2] != " ")
            {
                auto matchStr = t_matches[2].str();
                matchStr.erase(remove_if(matchStr.begin(), matchStr.end(), isspace), matchStr.end());
                result = t_matches[1].str() + matchStr;
            }
            else
            {
                result = t_matches[1].str() + "1";
            }
        }
        else
        {
            result = "0";
        }
        return stof(result);
    };

    std::regex realCompPattern("(-?)([0-9.]+)*[^ijk]([+]|-|$)");
    std::regex_search(t_quaternion, matches, realCompPattern);

    float w;
    if (!matches.empty())
    {
        w = std::stof(matches[0]);
    }
    else
    {
        w = 0;
    }
    auto i = g("i", t_quaternion, matches);
    auto j = g("j", t_quaternion, matches);
    auto k = g("k", t_quaternion, matches);

    std::array<float, 4> values = { w, i, j, k };
  return values;
}

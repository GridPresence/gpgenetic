#include <string>
#include <map>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
using Response = std::map<double, double>;

namespace ns
{
    class Context
    {
    private:
        int stages;
        int sample_rate;
        Response frequency_response;

    public:
        Context(std::string &config);
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Context, stages, sample_rate, frequency_response);
    };
}
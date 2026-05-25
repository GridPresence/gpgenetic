#include <string>
#include <map>

using Response = std::map<int, double>;

class Context
{
private:
    int stages;
    int sample_rate;
    Response frequency_response;

public:
    Context(std::string &config);
};

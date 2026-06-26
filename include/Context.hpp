#include "rapidjson/document.h"
#include <stdexcept>
#include <string>
#include <map>
#include <vector>

using Freqs = std::vector<double>;
using Omega = std::vector<double>;
using Bodes = std::vector<double>;
using Response = std::vector<double>;

class Context
{
private:
    int stages;
    double sample_rate;
    Freqs frequencies;
    Omega normalised_frequencies;
    Bodes decibels;
    Response linear_responses;

    bool IsValid(rapidjson::Document &doc);

public:
    Context(std::string &config);
};


// Base exception for our class
class ContextException : public std::runtime_error {
public:
    ContextException(const std::string& message) 
        : std::runtime_error(message) {}
};

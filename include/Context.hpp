#include "rapidjson/document.h"
#include <stdexcept>
#include <string>
#include <map>
#include <vector>

using DblVec = std::vector<double>;
//using Omega = std::vector<double>;
//using Bodes = std::vector<double>;
//using Response = std::vector<double>;

class Context
{
private:
    int m_stages;
    double m_sample_rate;
    DblVec m_frequencies;
    DblVec m_normalised_frequencies;
    DblVec m_decibels;
    DblVec m_linear_responses;

    bool IsValid(rapidjson::Document &doc);

public:
    Context(std::string &config);

    int stages();
    double rate();

    DblVec& freqs();
    DblVec& omegas();
    DblVec& dbs();
    DblVec& response();

    void linearise_bode();
    void enbode();
};

inline int Context::stages()
{
    return m_stages;
};

inline double Context::rate()
{
    return m_sample_rate;
};

inline DblVec& Context::freqs()
{
    return m_frequencies;
};

inline DblVec& Context::omegas()
{
    return m_normalised_frequencies;
};

inline DblVec& Context::dbs()
{
    return m_decibels;
};

inline DblVec& Context::response()
{
    return m_linear_responses;
};

// Base exception for our class
class ContextException : public std::runtime_error {
public:
    ContextException(const std::string& message) 
        : std::runtime_error(message) {}
};

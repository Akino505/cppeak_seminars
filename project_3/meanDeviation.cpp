#include "meanDeviation.hpp"

int mean(std::vector<double> vect, int length) 
{
    double result = 0;
    for(int idx = 0; idx < length; ++idx) 
    {
        result += vect[idx];
    }
    return result / length;
}

double dispertion(std::vector<double> vect, double mean, int length) 
{
    double result = 0;
    for(int idx = 0; idx < length; ++idx)
    {
        result += ((vect[idx] - mean) * (vect[idx] - mean));
    }
    result /= length;
    result = std::sqrt(result);
    return result;
}


double meanDeviation(std::vector<double> storage, int rws, int col) 
{
    double meanValue = mean(storage, rws * col);
    double meanDeviationValue = dispertion(storage, meanValue, rws * col);
    return meanDeviationValue;
}

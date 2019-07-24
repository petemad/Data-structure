#ifndef ECG_HPP
#define ECG_HPP

#include "arrays.hpp"
namespace ecg
{
struct Statistics
{
    double mean;
    double variance;
    double min;
    double max;
};

using ECGArray = arrays::DoubleArray; 

Statistics analyzeECG(ECGArray ecg)
{
    ecg::Statistics analysis;
    analysis.mean = arrays::meanArray(ecg.base, ecg.size);
    analysis.variance = arrays::varianceArray(ecg.base, ecg.size);
    analysis.max = arrays::maxArray(ecg.base, ecg.size);
    analysis.min = arrays::minArray(ecg.base, ecg.size);
    return analysis;
}

void analyzeECG(double *base, int arraySize, double &mean, double &variance, double &max, double &min)
{
    mean = arrays::meanArray(base, arraySize);
    variance = arrays::varianceArray(base, arraySize);
    max = arrays::maxArray(base, arraySize);
    min = arrays::minArray(base, arraySize);
}
}
#endif // ECG_HPP

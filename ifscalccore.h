#ifndef IFSCALCCORE_H
#define IFSCALCCORE_H

#include <vector>
#include <random>

#include "transformfunction.h"

class IFSCalcCore
{
public:
    IFSCalcCore();
    IFSCalcCore(Point init);

    ~IFSCalcCore();

    void addFunction(TransformFunction f);

    Point step();

private:
    void _initRandom();
    void _normWeights();
    int selectFunction();

    Point current;
    std::vector<TransformFunction> functions;
    std::random_device* rd;
    std::mt19937* gen;
    std::uniform_real_distribution<>* dist;
};

#endif // IFSCALCCORE_H

#include "ifscalccore.h"

IFSCalcCore::IFSCalcCore()
{
    this->current = Point(0.0, 0.0);
    this->_initRandom();
}

IFSCalcCore::IFSCalcCore(Point init)
{
    this->current = init;
    this->_initRandom();
}

IFSCalcCore::~IFSCalcCore()
{
    delete rd;
    delete gen;
    delete dist;
}

void IFSCalcCore::_initRandom()
{
    this->rd = new std::random_device;
    this->gen = new std::mt19937(*this->rd);
    this->dist = new std::uniform_real_distribution<>(0.0, 1.0);
}

void IFSCalcCore::addFunction(TransformFunction f)
{
    functions.push_back(f);
    this->_normWeights();
}

Point IFSCalcCore::step()
{
    int functionIndex = this->selectFunction();
    current = functions[functionIndex].transform(current);
    return current;
}

void IFSCalcCore::_normWeights()
{
    double total = 0.0;
    for (TransformFunction f : functions) {
        total += f.weight;
    }
    for (auto it = functions.begin(); it != functions.end(); it++) {
        it->weight = it->weight / total;
    }
}

int IFSCalcCore::selectFunction()
{
    double rand01 = (*dist)(*gen); // Random number in range [0,1]
    double weigetAdder = functions[0].weight;
    int counter = 0;
    while (weigetAdder < rand01) {
        weigetAdder += functions[++counter].weight;
    }
    return counter;
}

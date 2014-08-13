#include "bit_vector.hh"
#include "number_generator.hh"
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <limits>
#include <list>

void testBitVector(int numTests, std::string testFileName, size_t maxNumber = 10000000, size_t vectorLength = 1000000, size_t uniqueness = 1)
{
    double totalDuration = std::numeric_limits<double>::min();
    double maxTime = std::numeric_limits<double>::min();
    double minTime = std::numeric_limits<double>::max();

    std::cout << "running tests for bit vector implementation" << std::endl;
    std::cout << "running test ";
    for (int i = 0; i < numTests; ++i)
    {
        NumberGenerator::Instance()->generate(testFileName, maxNumber, vectorLength, uniqueness);
        std::cout << (i + 1);
        std::cout.flush();
        std::clock_t start;
        double duration;

        start = std::clock();

        BitVector::Instance(maxNumber)->hydrate(testFileName);
        BitVector::Instance()->writeBack(testFileName);
        delete BitVector::Instance();

        duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

        if (duration > maxTime)
            maxTime = duration;
        if (duration < minTime)
            minTime = duration;

        totalDuration += duration;
        for (int j = 0; j < ((int)(log10(i + 1)) + 1); ++j)
        {
            std::cout << "\b";
        }

        std::cout.flush();
    }

    std::cout << std::endl;

    double avgTime = totalDuration / numTests;

    std::cout << "tests complete for bit vector implementation" << std::endl;
    std::cout << "ran " << numTests << " tests" << std::endl;
    std::cout << "avg time: " << avgTime << "s" << std::endl;
    std::cout << "max time: " << maxTime << "s" << std::endl;
    std::cout << "min time: " << minTime << "s" << std::endl;
    return;
}

void testIntList(int numTests, std::string testFileName, size_t maxNumber = 10000000, size_t vectorLength = 1000000, size_t uniqueness = 1)
{
    double totalDuration = 0;
    double maxTime = std::numeric_limits<double>::min();
    double minTime = std::numeric_limits<double>::max();

    std::cout << "running tests for std::list<int> implementation" << std::endl;
    std::cout << "running test ";
    for (int i = 0; i < numTests; ++i)
    {
        NumberGenerator::Instance()->generate(testFileName, maxNumber, vectorLength, uniqueness);
        std::cout << (i + 1);
        std::cout.flush();
        std::clock_t start;
        double duration;

        start = std::clock();

        // create the list
        std::list<int> *intList = new std::list<int>();

        // open the file and hydrate the list
        std::ifstream inputFile;
        inputFile.open(testFileName);

        std::string line;
        while(getline(inputFile, line))
        {
            intList->push_front(atoi(line.c_str()));
        }

        inputFile.close();

        // sort the list
        intList->sort();

        // write the sorted list back to disk
        std::ofstream outputFile;
        outputFile.open(testFileName);

        for (std::list<int>::iterator index = intList->begin(); index != intList->end(); ++index)
        {
            outputFile << *index << std::endl;
        }

        outputFile.close();

        delete intList;

        duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

        if (duration > maxTime)
            maxTime = duration;
        if (duration < minTime)
            minTime = duration;

        totalDuration += duration;
        for (int j = 0; j < ((int)(log10(i + 1)) + 1); ++j)
        {
            std::cout << "\b";
        }

        std::cout.flush();
    }

    std::cout << std::endl;

    double avgTime = totalDuration / numTests;

    std::cout << "tests complete for std::list<int> implementation" << std::endl;
    std::cout << "ran " << numTests << " tests" << std::endl;
    std::cout << "avg time: " << avgTime << "s" << std::endl;
    std::cout << "max time: " << maxTime << "s" << std::endl;
    std::cout << "min time: " << minTime << "s" << std::endl;
    return;
}


int main (int argc, char *argv[])
{
    int numTests = 10;
    std::string testFileName = "./phone_numbers.dat";

    if (argc > 1) {
        numTests = atoi(argv[1]);
        if (argc > 2)
            testFileName = argv[2];
    }

    testBitVector(numTests, testFileName, 10000000, 1000000, 1);
    testIntList(numTests, testFileName, 10000000, 1000000, 1);

    return 0;
}

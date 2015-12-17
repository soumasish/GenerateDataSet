#include <iostream>
#include <fstream>
#include <random>

int main()
{
    const int NUM_VERTICES = 1024;
    const int NUM_EDGES = 2048;
    clock_t begin, end;
    double time_spent;

    int first, second;
    std::string path1 ="../../SerialBFS-Queue/DataSet/" + std::to_string(NUM_VERTICES) +"-"+std::to_string(NUM_EDGES) + ".txt";;
    std::string path2 ="../../ParallelBFS/DataSet/" + std::to_string(NUM_VERTICES) +"-"+std::to_string(NUM_EDGES) + ".txt";;
    std::string path3 ="../DataSet/" + std::to_string(NUM_VERTICES) + "-"+std::to_string(NUM_EDGES) + ".txt";

    std::ofstream serial(path1);
    std::ofstream parallel(path2);
    std::ofstream local(path3);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, (NUM_VERTICES -1));
    begin = clock();
    for (int i = 0; i < NUM_EDGES; ++i)
    {
        first = dis(gen);
        second = dis(gen);
        serial << first << "\t" << second <<"\n";
        parallel << first <<"\t" << second << "\n";
        local << first <<"\t"<<second<<"\n";
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout<<"Time taken: "<< time_spent<< std::endl;

    return 0;
}
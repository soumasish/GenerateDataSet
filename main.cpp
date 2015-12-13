#include <iostream>
#include <fstream>

int main()
{
    const int NUM_VERTICES = 4096;
    const int NUM_EDGES = 4096;
    clock_t begin, end;
    double time_spent;

    int first, second;
    std::string path1 ="../../SerialBFS/DataSet/" + std::to_string(NUM_VERTICES) + ".txt";;
    std::string path2 ="../../ParallelBFS/DataSet/" + std::to_string(NUM_VERTICES) + ".txt";;
    std::string path3 ="../DataSet/" + std::to_string(NUM_VERTICES) + ".txt";

    std::ofstream serial(path1);
    std::ofstream parallel(path2);
    std::ofstream local(path3);

    begin = clock();
    for (int i = 0; i < NUM_EDGES; ++i)
    {
        first = (rand() % (NUM_VERTICES+1));
        second = (rand() % (NUM_VERTICES+1));
        serial << first << "\t" << second <<"\n";
        parallel << first <<"\t" << second << "\n";
        local << first <<"\t"<<second<<"\n";
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout<<"Time taken: "<< time_spent<< std::endl;

    return 0;
}
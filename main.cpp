#include <vector>
#include <easybenchmark.h>


int main() {


    // This is going to make some shit, to let us test performance
    std::vector<long long int> cp;
    std::vector<long long int> vector;
    for(int i=0; i<10000000; i++){
        vector.push_back(9223372036854775807);
    }



    Benchmark::start("iterator loop");
    cp.clear();
    for(unsigned int i=0;i<vector.size(); i++) { cp.push_back(vector[i]); }
    Benchmark::end<std::micro>();


    Benchmark::start("range-based loop");
    cp.clear();
    for( const auto& i : vector) { cp.push_back(i); }
    Benchmark::end<std::micro>();

    /*
     You may also use Benchmark::start() without giving name
     and Benchmark::end(), it would return miliseconds, but you may want other units

     so the simplest way is:

     Benchmark::start();
        --[Do something]--
     Benchmark::end();

    */


    return 0;
}


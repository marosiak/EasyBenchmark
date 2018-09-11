# EasyBenchmark

I've made this project because I wanted to be able, to quickly and easy benchmark what's faster solution, I'm bored of using raw std::chrono, so this "lib" does it faster.


## Example

```c++
#include <vector>
#include <easybenchmark.h>


int main() {
    // This is going to make some shit, to let us test performance
    std::vector<long long int> vector, cp;
    for(int i=0; i<10000000; i++){
        vector.push_back(9223372036854775807);
    }

    Benchmark::start("iterator loop"); // optional argument
    cp.clear();
    for(unsigned int i=0;i<vector.size(); i++) { cp.push_back(vector[i]); }
    Benchmark::end<std::micro>();

    Benchmark::start("range-based loop");
    cp.clear();
    for( const auto& i : vector) { cp.push_back(i); }
    Benchmark::end<std::micro>(); // optional template
}
```



## Benchmark::start();
* optional argument ***std::string name***

This is going to start the benchmark, as optional argument you can enter

## Benchmark::end();
* optional template ***<std::ratio>***
```c++
	Benchmark::end(); // Default it's miliseconds
	Benchmark::end<std::nano>();
```
This is going to end the test, and print message.
 
***example:***
```text
	[Benchmark] "range-based loop" passed in 249240 us
```

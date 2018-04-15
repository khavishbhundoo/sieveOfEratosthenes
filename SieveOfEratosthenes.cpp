#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>


using u_big = unsigned long long int;

std::vector<u_big> sieveOfEratosthenes(u_big &min, u_big &max) {
    std::vector<u_big> result;

    if (max <= 1 || min < 1 ) return result;

    if(min == 1) {
        min = 2; // skip 1 as it is not prime
    }

    if (max == 2) {
        result.push_back(max);
        return result;
    }


    /*
     * Declare a vector of boolean and ser all value to true
     * Consider all numbers to be prime at this point
     */
    std::vector<bool> primes(min + (max - min) + 1,true);

    auto sqrt_max = (u_big) sqrt(max);

    for (auto i = min; i < sqrt_max; i++ ) {
        if(primes.at(i)) {
            /*
             * Filter out non primes
             * Multiples of positive numbers cannot be primes
             */
            for (auto  j = i; i*j <= max; j++) {
                primes.at(i*j) = false;
            }
        }
    }

    for (auto  i = min; i <= max ; i++) {
        if (primes.at(i)) {
            result.push_back(i);
        }
    }

    return result;

}

void print(std::vector<u_big> result) {
    for ( auto const &i : result ) {
        std::cout << i << std::endl;
    }
}

void save(const std::string &filename,std::vector<u_big> &result) {
    std::ofstream outFile(filename);
    for (const auto &p : result)  outFile << p << "\n";

}

int main() {
    unsigned long long int min,max;
    std::cout << "Enter minimum : ";
    std::cin >> min;
    std::cout << "\nEnter maximum : ";
    std::cin >> max;
    int start_s=clock();
    std::vector<u_big> result = sieveOfEratosthenes(min,max);
    int stop_s=clock();
    std::cout << "Runtime to generate primes : " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << std::endl;
    std::cout << "Number of primes : " <<  result.size() << std::endl;
    std::cout << "Primes saved to primes.txt" << std::endl;
    save("primes.txt", result);
    //print(result);
    return 0;
}

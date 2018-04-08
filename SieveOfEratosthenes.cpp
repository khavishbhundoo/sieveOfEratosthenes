#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;
using u_big = unsigned long long int;

vector<u_big> sieveOfEratosthenes(u_big min, u_big max) {
    vector<u_big> result;

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
    vector<bool> primes(min + (max - min) + 1,true);

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

void print(vector<u_big> result) {
    for ( auto const &i : result ) {
        cout << i << std::endl;
    }
}

void save(const string &filename,vector<u_big> result) {
    ofstream outFile(filename);
    for (const auto &p : result)  outFile << p << "\n";

}

int main() {
    unsigned long long int min,max;
    cout << "Enter minimum : ";
    cin >> min;
    cout << "\nEnter maximum : ";
    cin >> max;
    int start_s=clock();
    vector<u_big> result = sieveOfEratosthenes(min,max);
    int stop_s=clock();
    cout << "Runtime to generate primes : " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << endl;
    cout << "Number of primes : " <<  result.size() << endl;
    cout << "Primes saved to primes.txt" << endl;
    save("primes.txt", result);
    //print(result);
    return 0;
}


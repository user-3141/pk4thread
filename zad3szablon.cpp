
#include <vector>
#include <thread>
#include <iostream>

std::vector<long long> GetFactors(long long n)
{
    std::vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

void f(const std::vector<long long>& nums, int beginIndex, int EndIndex, std::vector<std::vector<long long>>& factors)
{
    
}

int main()
{
    std::vector<long long> numbers = {343533055656878036,
                                      5860350457319753452,
                                      7893707073704431551,
                                      4368313902489077849,
                                      1677941465804505455,
                                      3297139368709694577,
                                      2233241309328876460,
                                      1429423566119835739,
                                      6516264611898389790,
                                      2442897970716511172,
                                      4090212017170405777,
                                      1153505978712351257,
                                      612345904729275297,
                                      2967311862877440092,
                                      7436859525682139307,
                                      8675552455193670309,
                                      5341853797610081834,
                                      8839889067931964805,
                                      2075530006345431709,
                                      6715788216943620268,
                                      865949283066326930,
                                      240626470966425323,
                                      3392424271198655643,
                                      4993821633716302940,
                                      5808357568576893759,
                                      7063755934051908169,
                                      5318084116412572738,
                                      7927635782097829856,
                                      4394970874296051547,
                                      5103438212726077733,
                                      3864573979507605197,
                                      163382648627135698};

    //wektory z wynikami faktoryzacji
    std::vector<std::vector<long long>> factors1;
    std::vector<std::vector<long long>> factors2a;
    std::vector<std::vector<long long>> factors2b;


    auto poczatek1 = std::chrono::high_resolution_clock::now();

    //pojedynczy wątek

    auto koniec1 = std::chrono::high_resolution_clock::now();
    long long int czas1 = std::chrono::duration_cast<std::chrono::milliseconds > (koniec1 - poczatek1).count();
    std::cout << "1 watek - czas: " << czas1 << std::endl;

    
    auto poczatek2 = std::chrono::high_resolution_clock::now();

    //2 watki

    auto koniec2 = std::chrono::high_resolution_clock::now();
    long long int czas2 = std::chrono::duration_cast<std::chrono::milliseconds > (koniec2 - poczatek2).count();
    std::cout << "2 watki - czas: " << czas2 << std::endl;
}

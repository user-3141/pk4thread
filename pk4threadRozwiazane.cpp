#include <iostream>
#include <string>
#include <vector>
#include <thread>


/* zad1

****Wynik****:
s    <-input
s 29 <-output
z    <-input
z 73 <-output
 (odstep czasu)
Watek t1 zakonczyl prace <-output


void zad1(int& z)
{
    while(z < 100)
    {
        ++z;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
*/


/* zad2

****wyniki****
Wyliczono 132 elementow ciagu Fibonaciego
Zakonczyc(t-tak)?:n <-input
 Wyliczono 487 elementow ciagu Fibonaciego
Zakonczyc(t-tak)?:gwgahghH <-input
 Wyliczono 848 elementow ciagu Fibonaciego
Zakonczyc(t-tak)?:ewfegs <-input
 Wyliczono 1442 elementow ciagu Fibonaciego
Zakonczyc(t-tak)?:t <-input
 Zatrzymano wyliczanie
Wyliczono 1602 elementow ciagu Fibonaciego


void f1(const std::stop_token& st, std::vector<int>& v)
{
    for(int i = 1; !st.stop_requested(); ++i)
    {
        v.push_back(v[i-1]+v[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds (1));
    }
}
void f2(const std::stop_token& st, std::stop_source ss, const std::vector<int>& v)
{
    std::string input;
    while(input != "t")
    {
        std::this_thread::sleep_for(std::chrono::seconds (2));
        std::cout << "Wyliczono " << v.size() << " elementow ciagu Fibonaciego\n" << "Zakonczyc(t-tak)?: ";
        std::cin >> input;
    }
    ss.request_stop();
    std::cout << "Zatrzymano wyliczanie\n";
    std::cout << "Wyliczono " << v.size() << " elementow ciagu Fibonaciego\n";
}
*/


/* zad3

****wyniki****
1 watek - czas: 35082
2 watki - czas: 18706


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
    for(int i = beginIndex; i<EndIndex; ++i)
    {
        factors.push_back(GetFactors(nums[i]));
    }
}
*/

int main()
{
    /* zad1
    int a = 0;
    std::thread t1(zad1, std::ref(a));

    std::string inpt = "";
    while (inpt != "z")
    {
        std::cin >> inpt;
        std::cout << inpt << " " << a << std::endl;
    }
    t1.join();
    std::cout << "Watek t1 zakonczyl prace" << std::endl;
    */


    /* zad 2
    std::vector<int> vector = {0,1};
    std::jthread t1(f1, std::ref(vector));
    std::jthread t2(f2, t1.get_stop_source(), std::ref(vector));
    t2.join();
     */


    /* zad3
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

    std::vector<std::vector<long long>> factors1;
    std::vector<std::vector<long long>> factors2a;
    std::vector<std::vector<long long>> factors2b;


    auto poczatek1 = std::chrono::high_resolution_clock::now();

    std::thread t1(f, std::ref(numbers), 0, numbers.size(), std::ref(factors1));
    t1.join();

    auto koniec1 = std::chrono::high_resolution_clock::now();
    long long int czas1 = std::chrono::duration_cast<std::chrono::milliseconds > (koniec1 - poczatek1).count();

    std::cout << "t1 - czas: " << czas1 << std::endl;



    auto poczatek2 = std::chrono::high_resolution_clock::now();

    std::thread t2a(f, std::ref(numbers), 0, numbers.size()/2, std::ref(factors2a));
    std::thread t2b(f, std::ref(numbers), numbers.size()/2, numbers.size(), std::ref(factors2b));
    t2a.join();
    t2b.join();

    auto koniec2 = std::chrono::high_resolution_clock::now();
    long long int czas2 = std::chrono::duration_cast<std::chrono::milliseconds > (koniec2 - poczatek2).count();

    std::cout << "t2 - czas: " << czas2 << std::endl;
    */
}

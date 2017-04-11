//
// Created by julia on 24.03.2017.
//

#include "Testy.h"


using namespace std;

long long int frequency, start, elapsed;
float times;
 float timems;
 float timeus;
 Tablica *a;

void zachowajCzas(){
    timeus= (float) ((1000000.0 * elapsed) / frequency);
}


long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void zapiszStatystykeDoPliku(std::string nazwapliku, float timeus) {
    std::ofstream plik;
    plik.open(nazwapliku, std::ios_base::app);
    plik<< timeus<<" ";
    plik.close();
}

void zapiszDoPliku(std::string nazwapliku, std::string tresc) {
    std::ofstream plik;
    plik.open(nazwapliku, std::ios_base::app);
    plik << tresc;
    plik.close();
}
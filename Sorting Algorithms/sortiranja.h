#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

//kolekcija algoritama za sortiranje
//jednostavni algoritmi O(n*n)
void selection_sort(int A[], int N);
void bubble_sort(int A[], int N);
void insertion_sort(int A[], int N);
void shell_sort(int A[], int N);
//slozeni algoritmi 0(nlog(n))
void merge_sort(int* array, int n);
void heap_sort(int* array, int n);
void quick_sort(int arr[], int n);
//pomocne funkcije
int lrand(int n); //generiranje long slucajnog broja do n
double diffclock(clock_t clock1, clock_t clock2); //razlika izmedju dva vremena u ms
void napuni_polje_rand(int* polje, int n); //puni polje slucajnim brojevima
void napuni_polje_az(int* polje, int n); //puni polje brojevima 1..n
void napuni_polje_za(int* polje, int n); //puni polje brojevima n..1
void ispisi_polje(int* polje, int n); //ispisi polje za test

#include "guessga.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int random0or1(){
    
    if (rand() % 2 == 0)
    {
        return 1 ;
    }
    else 
        return 0 ;

}

/* Fitness function F = k^2 ,where k number of equal bits */
int fitness(int *purespecimen , int *checkspecimen ,int length){
    int k , i ;
    k = 0 ;
    for (i = 0; i < length; ++i)
    {
        if (purespecimen[i] == checkspecimen[i])
        {
            k++;
        }
    }
    return (k*k) ;
}

double random0to1(){
    double getrandom ;
    getrandom = rand() ;

    if(getrandom != RAND_MAX )
        return getrandom / RAND_MAX;
    else
        return random0to1() ;
}

int rand_interval(int max){ /* Source : lists.di.uoa.gr */
	int random ;
	const int range = 1 + max ;
    const int buckets = RAND_MAX / range ;
    const int limit = buckets * range ;
    do
    {
    	random = rand() ;
    }while(random >= limit);

    return (random / buckets) ;
}

/* Swaps the values of the 2 arrays up to cross */
void crossover(int *a,int *b ,int length){	
    int cross = rand_interval(length - 1) ;
    int temp[length] ;
    
    int i ;
    for (i = 0; i < cross; ++i)	
    {
        temp[i] = a[i] ;
        a[i] = b[i] ;
        b[i] = temp[i] ;
    }
}
void merge_temp(int *x,int *y,int size ,int length) /* Makes temporary population into current */ 
{
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < length; ++j)
        {
            y[i][j] = x[i][j] ;
        }
    }
}
void clear_array(int x,int size,int length)     /* Sets all values of array to zero */
{
    for (i = 0; i < size; ++i)
    {
        for (j = 0; i < length; ++j)
        {
            x[i][j] = 0 ;
        }
    }
}
void init_population(int *population,int size ,int length)
{
    int i ,j ;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < count; ++j)
        {
            population[i][j] = random0or1();
        }
    }
}
double get_average_population(int x,int specimen ,int size ,int length)
{
    int sum = 0 ,i ;
    for (i = 0; i < size; ++i)
    {
        sum += fitness(x[i],specimen,length);
    }
    return ((double) (sum / size));
}
int get_max_member(int x ,int specimen,int size,int length,int *place)
{
    int i ,max = 0 ,place = 0 ;
    max = fitness(x[0],specimen,length);

    for (i = 1; i < ; ++i)
    {
        tmp = fitness(x[i],specimen,length);
        if (tmp > max)
        {
            max = tmp;
            *place = i ;
        }
    }
    return max ;
}
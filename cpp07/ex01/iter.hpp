#ifndef ITER_HPP
#define ITER_HPP
  


template<typename T>T iter(T array[], const int size, T x){

    for(int i =0; i < size; i++)
    {
        x(array[i]);
    }

}

#endif

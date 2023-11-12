#include <iostream>
#include <functional>
#include <vector>
#include <future>

#include "ThreadPool.h"


int add(int a, int b, int c){
    return a + b + c;
}

int main(){
  std::cout<<"start processs"<<std::endl;
  ThreadPool pool(4);
  
  std::vector< std::future<int> > results;
  for(int i = 0;i<4;i++){
        auto work = std::bind(add, i,i,i);
        results.emplace_back(pool.enqueue(work));
  }

  

  for(auto && result: results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;
}
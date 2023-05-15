#include <iostream>
#include <utility>
#include "PmergeMe.hpp"

// int ft_rand() {
//     return (std::rand() % 10000000);
// };

// void startTime() {
//      std::high_resolution_clock::time_point t1 = std::high_resolution_clock::now();
// }

// int main(int ac, char **av) {
//     (void)ac;
//     (void)av;

//     if (ac > 1) {
//         try
//         {
//             PmergeMe merge;
//             merge.fillContainer(std::strtol(av[1], NULL, 10));
//             // PmergeMe merge;
//             // int i  = 1;
//             // while (i < ac) {
//             //     int tmp = std::strtol(av[i++], NULL, 10);
//             //     merge.addNum(tmp);
//             // }
//             // // merge.printData();
//             // merge.sortVector();
//             // // merge.printData();
//             // merge.isSorted();
//             // merge.printDataList();
//             // merge.printDataList();
//             gettimeof
//             merge.sortList();
//             merge.isSortedList();
//             merge.sortVector();
//             merge.isSortedVector();
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << '\n';
//         }
//     }
// }


// * time example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
int main ()
{
  time_t timerStart;
  time_t timerEnd;
  double seconds;


  time(&timerStart);  /* get current time; same as: timer = time(NULL)  */
  std::this_thread::sleep_for(std::chrono::useconds(1));
  time(&timerEnd);  /* get current time; same as: timer = time(NULL)  */
   std::cout << difftime(timerEnd, timerStart) << std::endl;


  return 0;
}
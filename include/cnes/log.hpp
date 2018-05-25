#pragma once

#include <iostream>

#define LOG_HEAD_START "[\e[1m"<<__FILE__<<"\e[0m:\e[1m"<<__LINE__<<"\e[0m] "
#define LOG_INFO  LOG_HEAD_START
#define LOG_WARN  LOG_HEAD_START<<"[\e[34mWarning\e[0m] "
#define LOG_ERROR LOG_HEAD_START<<"[\e[31mError\e[0m] "
#define LOG_CRIT  LOG_HEAD_START<<"[\e[32mCritical\e[0m] "

#define linfo  std::cout<<LOG_INFO
#define lwarn  std::cout<<LOG_WARN
#define lerror std::cout<<LOG_ERROR
#define lcrit  std::cout<<LOG_CRIT

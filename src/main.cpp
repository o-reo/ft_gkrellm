#include "Logger.hpp"

int main(void) {
  Logger *logger = Logger::get();
  logger->out() << "Initializing" << std::endl;
  return (0);
}
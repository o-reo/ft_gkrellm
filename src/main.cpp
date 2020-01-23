#include "Logger.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main(void) {
  Logger *logger = Logger::get();
  logger->out() << "Initializing" << std::endl;
  sf::Window window(sf::VideoMode(800, 600), "My window");
  return (0);
}
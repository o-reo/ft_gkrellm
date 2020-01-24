#include "Logger.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main(void) {
  Logger *logger = Logger::get();
  logger->out() << "Initializing" << std::endl;
  sf::RenderWindow window;
  window.create(sf::VideoMode(800, 600), "School invaders", sf::Style::Close | sf::Style::Titlebar);
  return (0);
}
#include "SRender.hh"

SRender::SRender() : focused(NULL), env_ready(false) {

}

SRender::~SRender() {
}

bool SRender::start(const std::string &title, int width, int height) {
  w = width;
  h = height;

  settings.antialiasingLevel = 8;
  win.create(sf::VideoMode(w, h), title.c_str(), sf::Style::Default, settings);
  font.loadFromFile("arial.ttf");
  env_ready = true;
  return true;
}

sf::RenderWindow  &SRender::getWin() {
  return win;
}

sf::Font          &SRender::getFont() {
  return font;
}

bool SRender::isOpen() {
  return win.isOpen();
}

void SRender::close() {
  win.close();
}

int       SRender::update(sf::Event &event) {
  return win.pollEvent(event);
}

void        SRender::clear() {
  win.clear();
}

void        SRender::display() {
   win.display();
}

Entity  *SRender::focus(Entity *e) {
  if (e != NULL)
    focused = e;
  return focused;
}

int   SRender::getWidth() {
  return w;
}

int   SRender::getHeight() {
  return h;
}

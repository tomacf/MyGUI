#include "Factory.hh"
#include <iostream>

void mouse_down_button_fct(Entity *vm, sf::Event  &event) {
  vm->getAttr<GEOMETRY>()->set("focused", 1);
  vm->getAttr<GEOMETRY>()->set("mousex", event.mouseButton.x);
  vm->getAttr<GEOMETRY>()->set("mousey", event.mouseButton.y);
}

void mouse_move_button_fct(Entity *vm, sf::Event  &event) {
  if (vm->getAttr<GEOMETRY>()->get("focused") == 0)
    return;
  int x = vm->getAttr<GEOMETRY>()->get("mousex");
  int y = vm->getAttr<GEOMETRY>()->get("mousey");

  vm->getAttr<GEOMETRY>()->set("mousex", event.mouseMove.x);
  vm->getAttr<GEOMETRY>()->set("mousey", event.mouseMove.y);
  vm->getAttr<GEOMETRY>()->substract("x", x - event.mouseMove.x);
  vm->getAttr<GEOMETRY>()->substract("y", y - event.mouseMove.y);
}

void mouse_up_button_fct(Entity *vm, sf::Event  &event) {
  vm->getAttr<GEOMETRY>()->set("focused", 0);
}


void mouse_up_fct(Entity *vm, sf::Event  &ev) {
  vm->getAttr<GEOMETRY>()->substract("x", 2);
  vm->getAttr<GEOMETRY>()->substract("y", 2);
  vm->getAttr<GEOMETRY>()->add("w", 4);
  vm->getAttr<GEOMETRY>()->add("h", 4);
}

void  key_press_on_textarea(Entity *vm, sf::Event  &ev) {
  std::string label = vm->getAttr<LABEL>()->getLabel();

  switch (ev.key.code) {
    case sf::Keyboard::Key::Right:
      std::cout << "cursor right" << std::endl;
      break;
    case sf::Keyboard::Key::Space:
      label.push_back(' ');
      break;
    case sf::Keyboard::Key::Return:
      label.push_back('\n');
      break;
    case sf::Keyboard::Key::BackSpace:
      label.pop_back();
      break;
    default:
      if (ev.text.unicode <= 26) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
          label.push_back('A' + ev.text.unicode);
        else
          label.push_back('a' + ev.text.unicode);
      }

      break;
  }
  vm->getAttr<LABEL>()->setLabel(label);
}

void key_press_fct(Entity *vm, sf::Event  &ev) {
  if (ev.key.code == sf::Keyboard::Key::Left) {
    vm->getAttr<GEOMETRY>()->substract("x", 10);
  }
  else if (ev.key.code == sf::Keyboard::Key::Right) {
    vm->getAttr<GEOMETRY>()->add("x", 10);
  }
  else if (ev.key.code == sf::Keyboard::Key::Up) {
    vm->getAttr<GEOMETRY>()->substract("y", 10);
  }
  else if (ev.key.code == sf::Keyboard::Key::Down) {
    vm->getAttr<GEOMETRY>()->add("y", 10);
  }
  else {
    std::cout << "Something else" << std::endl;
  }
}


int main(int ac, char **av)
{
  SRender   render;
  Factory   builder(&render);
  bool      terminer(false);

  render.start();

  Entity *pict = builder.buildImage();
  pict->getAttr<GEOMETRY>()->set("x", 0)->set("y", 0);

  Entity *rectangle = builder.buildRectangle();
  rectangle->getAttr<GEOMETRY>()->set("x", 0)->set("y", 0)->set("w", 200)->set("h", 600);
  rectangle->getAttr<COLOR>()->setRGBA(20, 220, 50, 100);
  rectangle->getAttr<EVENT>()->setEvent(sf::Event::MouseButtonPressed, &mouse_up_fct);
  rectangle->getAttr<EVENT>()->setEvent(sf::Event::KeyPressed, &key_press_fct);

  Entity *cercle = builder.buildCircle();
  cercle->getAttr<GEOMETRY>()->set("x", 100)->set("y", 100)->set("w", 10);
  cercle->getAttr<COLOR>()->setRGBA(255, 255, 0, 100);
  cercle->getAttr<EVENT>()->setEvent(sf::Event::MouseButtonPressed, &mouse_up_fct);
  cercle->getAttr<EVENT>()->setEvent(sf::Event::KeyPressed, &key_press_fct);

  Entity *triangle = builder.buildTriangle();
  triangle->getAttr<GEOMETRY>()->set("x", 400)->set("y", 200)->set("w", 100);
  triangle->getAttr<COLOR>()->setRGBA(255, 255, 0, 100);
  triangle->getAttr<EVENT>()->setEvent(sf::Event::MouseButtonPressed, &mouse_up_fct);
  triangle->getAttr<EVENT>()->setEvent(sf::Event::KeyPressed, &key_press_fct);

  Entity *line = builder.buildLine();
  line->getAttr<GEOMETRY>()->set("x1", 10)->set("y1", 40)->set("x2", 600)->set("y2", 300);
  triangle->getAttr<COLOR>()->setRGBA(255, 50, 255, 100);

  Entity *title = builder.buildLabel();
  title->getAttr<GEOMETRY>()->set("x", 355)->set("y", 40);
  title->getAttr<COLOR>()->setRGBA(165, 223, 85, 100);
  title->getAttr<LABEL>()->setLabel("Dashboard");

  Entity *button = builder.buildButton();
  button->getAttr<GEOMETRY>()->set("x", 500)->set("y", 200)->set("w", 200)->set("h", 100);
  button->getAttr<COLOR>()->setRGBA(165, 223, 85, 100);
  button->getAttr<LABEL>()->setLabel("Swegtown");
  button->getAttr<EVENT>()->setEvent(sf::Event::MouseButtonPressed, &mouse_down_button_fct);
  button->getAttr<EVENT>()->setEvent(sf::Event::MouseMoved, &mouse_move_button_fct);
  button->getAttr<EVENT>()->setEvent(sf::Event::MouseButtonReleased, &mouse_up_button_fct);

  Entity *textarea = builder.buildTextBox();
  textarea->getAttr<GEOMETRY>()->set("x", 300)->set("y", 50)->set("w", 300)->set("h", 150);
  textarea->getAttr<COLOR>()->setRGBA(165, 223, 85, 100);
  textarea->getAttr<EVENT>()->setEvent(sf::Event::KeyPressed, &key_press_on_textarea);

  Entity *page = builder.buildPage();
  page->getAttr<CHILDREN>()->push(pict);
  page->getAttr<CHILDREN>()->push(rectangle);
  page->getAttr<CHILDREN>()->push(cercle);
  page->getAttr<CHILDREN>()->push(triangle);
  page->getAttr<CHILDREN>()->push(line);
  page->getAttr<CHILDREN>()->push(title);
  page->getAttr<CHILDREN>()->push(button);
  page->getAttr<CHILDREN>()->push(textarea);

  render.clear();
  page->getAttr<DRAW>()->draw();
  render.display();

  while(!terminer)
  {
    sf::Event e;
    while (render.update(e))
      {
        if (e.type == sf::Event::Closed)
          terminer = true;
        page->getAttr<EVENT>()->checkEvent(e);
      }
    render.clear();

    page->getAttr<DRAW>()->draw();

    render.display();
  }
}
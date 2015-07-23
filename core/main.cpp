#include "Factory.hh"
#include <iostream>

void mouse_up_fct(Entity *vm, SDL_Event  &ev) {
  vm->getAttr<GEOMETRY>()->setX(vm->getAttr<GEOMETRY>()->getX()+1);
  vm->getAttr<GEOMETRY>()->setY(vm->getAttr<GEOMETRY>()->getY()+1);
  vm->getAttr<GEOMETRY>()->setW(vm->getAttr<GEOMETRY>()->getW()+1);
  vm->getAttr<GEOMETRY>()->setH(vm->getAttr<GEOMETRY>()->getH()+1);
}

int main(int ac, char **av)
{
  SRender   render;
  Factory   builder(&render);
  bool      terminer(false);

  render.init();
  render.start();

  Entity *button = builder.buildButton();
  button->getAttr<LABEL>()->setLabel("Test");
  button->getAttr<GEOMETRY>()->setX(10)->setY(10)->setW(20)->setH(20);
  button->getAttr<COLOR>()->setRGBA(0, 255, 0, 255);
  button->getAttr<EVENT>()->setEvent(MouseUp, &mouse_up_fct);


  Entity *button1 = builder.buildButton();
  button1->getAttr<LABEL>()->setLabel("Test");
  button1->getAttr<GEOMETRY>()->setX(10)->setY(10)->setW(20)->setH(20);
  button1->getAttr<COLOR>()->setRGBA(0, 255, 0, 255);
  button1->getAttr<EVENT>()->setEvent(MouseUp, &mouse_up_fct);


  Entity *page = builder.buildPage();
  page->getAttr<CHILDREN>()->push(button);

  render.clear();
  page->getAttr<DRAW>()->draw();
  render.draw();

  while(!terminer)
  {
    page->getAttr<DRAW>()->draw();
    render.draw();
    if (render.updateWait().window.event == SDL_WINDOWEVENT_CLOSE)
      terminer = true;
    page->getAttr<EVENT>()->checkEvent();
    render.clear();
  }
}
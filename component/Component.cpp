#include "Component.hh"

Component::Component() {
  change = true;
}

Component::~Component() {

}

bool  Component::hasChange() {
  if (change == true) {
    change = false;
    return true;
  }
  return false;
}
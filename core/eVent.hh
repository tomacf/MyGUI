#ifndef GUI_EVENT_HH
#define GUI_EVENT_HH

enum eVent
{
  none,
  MouseUp,
  MouseDown,
  Click,
  DoubleClick,
  TripleClick,
  MouseRightClick,
  MouseChord,
  MouseEnter,
  MouseMove,
  MouseOut,
  MouseStartDrag,
  MouseDraging,
  MouseStopDrag,
  ReceiveDrag,
  MouseWheelUp,
  MouseWheelDown,
  GotFocus,
  LostFocus,
  KeyPressed,
  KeyReleased,
  TextEntered,
  Resized
};

#endif
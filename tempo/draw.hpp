#include "stdafx.h"

void loopy(HDC hdc)
{
  COLORREF sky = RGB(34, 141, 203);
  COLORREF ground = RGB(0, 197, 0);
  COLORREF road = RGB(142, 140, 142);
  COLORREF marker1 = RGB(255, 46, 0);
  COLORREF marker2 = RGB(255, 255, 255);

  RECT r = { 10,10,10 + 320,10 + 120 };
  HBRUSH brush = CreateSolidBrush(sky);
  FillRect(hdc, &r, brush);

  r = { 10,10 + 120,10 + 320,10 + 240 };
  brush = CreateSolidBrush(ground);
  FillRect(hdc, &r, brush);

  // road
  brush = CreateSolidBrush(road);
  SelectObject(hdc, brush);
  HPEN hGray = CreatePen(PS_SOLID, 1, road);
  SelectObject(hdc, hGray);
  POINT apt[4] = { { 10,10 + 240 },{ 10 + 160 - 20,10 + 120 },{ 10 + 160 + 20,10 + 120 } ,{ 10 + 320,10 + 240 } };
  Polygon(hdc, apt, 4);

  // marker red
  HPEN hRed = CreatePen(PS_SOLID, 4, marker1);
  SelectObject(hdc, hRed);
  apt[0] = { 10,10 + 240 };
  apt[1] = { 10 + 160 - 20, 10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 320,10 + 240 };
  apt[1] = { 10 + 160 + 20,10 + 120 };
  Polyline(hdc, apt, 2);

  apt[0] = { 10,10 + 235 };
  apt[1] = { 10 + 160 - 20, 10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 320,10 + 235 };
  apt[1] = { 10 + 160 + 20,10 + 120 };
  Polyline(hdc, apt, 2);

  apt[0] = { 10,10 + 230 };
  apt[1] = { 10 + 160 - 20, 10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 320,10 + 230 };
  apt[1] = { 10 + 160 + 20,10 + 120 };
  Polyline(hdc, apt, 2);


  // marker white
  HPEN hWhite = CreatePen(PS_SOLID, 4, marker2);
  SelectObject(hdc, hWhite);
  apt[0] = { 10 + 160 - 60,10 + 240 };
  apt[1] = { 10 + 160 - 10,10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 160 + 60,10 + 240 };
  apt[1] = { 10 + 160 + 10,10 + 120 };
  Polyline(hdc, apt, 2);

  apt[0] = { 10 + 160 - 55,10 + 240 };
  apt[1] = { 10 + 160 - 10,10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 160 + 55,10 + 240 };
  apt[1] = { 10 + 160 + 10,10 + 120 };
  Polyline(hdc, apt, 2);

  SetBkColor(hdc, sky);
  TextOutA(hdc, 30, 30, "Pseudo 3D cheated", 17);
}

void loopy2(HDC hdc)
{
  COLORREF sky = RGB(34, 141, 203);
  COLORREF ground = RGB(0, 197, 0);
  COLORREF road = RGB(142, 140, 142);
  COLORREF marker1 = RGB(255, 46, 0);
  COLORREF marker2 = RGB(255, 255, 255);

  RECT r = { 10,10,10 + 320,10 + 120 };
  HBRUSH brush = CreateSolidBrush(sky);
  FillRect(hdc, &r, brush);
  DeleteObject(brush);

  r = { 10,10 + 120,10 + 320,10 + 240 };
  brush = CreateSolidBrush(ground);
  FillRect(hdc, &r, brush);
  DeleteObject(brush);

  // road
  brush = CreateSolidBrush(road);
  SelectObject(hdc, brush);
  HPEN hGray = CreatePen(PS_SOLID, 1, road);
  SelectObject(hdc, hGray);
  POINT apt[4] = { { 10,10 + 240 },{ 10 + 160 - 20,10 + 120 },{ 10 + 160 + 20,10 + 120 } ,{ 10 + 320,10 + 240 } };
  Polygon(hdc, apt, 4);
  DeleteObject(hGray);
  DeleteObject(brush);


/*
  HPEN hRed   = CreatePen(PS_SOLID, 4, marker1);
  HPEN hWhite = CreatePen(PS_SOLID, 4, marker2);
  static int texpos = 0;
  for (int i = 240; i > 120; i--)
  {

    Polygon(hdc, apt, 4);

    texpos++;
    if (texpos > 10) texpos = 0;
  }
  */
}

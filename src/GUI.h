/*
 * GUI.h
 *
 *  Created on: Dec 4, 2017
 *      Author: s105308
 */

#ifndef SRC_GUI_H_
#define SRC_GUI_H_

#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow);


#endif /* SRC_GUI_H_ */

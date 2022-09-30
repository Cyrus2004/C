import datetime

import os
import win32gui, win32con

window = win32gui.GetForegroundWindow()

win32gui.ShowWindow(window, win32con.SW_SHOW)

f = open("birthdays", "r")
print(f.read())
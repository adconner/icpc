#!/bin/sh
setxkbmap dvorak
xmodmap -e 'remove Lock = Caps_Lock'\
 -e 'remove Control = Control_L'\
 -e 'keysym Caps_Lock = Control_L'\
 -e 'add Lock = Caps_Lock'\
 -e 'add Control = Control_L'

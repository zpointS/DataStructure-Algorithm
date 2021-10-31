@echo off
::call clean.bat
@echo on
AVL.exe nn.txt
dot.exe -Tpng avl.gv -o avl.png
pause
import os
import time
os.system('gcc main.c -o main -lncurses')
time.sleep(0.5)
os.system('./main')

#!/bin/bash
/usr/bin//valgrind --leak-check=full ./dist/Debug/GNU-Linux/shopping4__1_ -noargs < ./tests/validation/ErrorData.keyboard 1> /dev/null 2>> ./tests/output/ErrorData.mleaks.full

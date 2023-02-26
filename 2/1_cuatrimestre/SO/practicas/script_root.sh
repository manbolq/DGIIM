#!/bin/bash

cp ~/Escritorio/DGIIM/2º/1º\ cuatrimestre/SO/practicas/kernel32-3.0.4.gz /tmp
cp ~/Escritorio/DGIIM/2º/1º\ cuatrimestre/SO/practicas/Fedora14-x86-root_fs.gz /tmp
gunzip /tmp/*.gz
chmod u+x /tmp/kernel32-3.0.4
/tmp/kernel32-3.0.4 ubda=/tmp/Fedora14-x86-root_fs mem=1024m

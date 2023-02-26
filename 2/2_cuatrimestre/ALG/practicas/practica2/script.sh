#!/bin/bash
echo "2_k_const...";
./2_k_const >> 2_k_const.dat;
echo "2_k_const terminado";
echo "2_k_const_binary...";
./2_k_const_binary >> 2_k_const_binary.dat;
echo "2_k_const_binary terminado";
echo "2_n_const...";
./2_n_const >> 2_n_const.dat;
echo "2_n_const terminado";
echo "2_n_const_binary...";
./2_n_const_binary >> 2_n_const_binary.dat;
echo "2_n_const_binary terminado";

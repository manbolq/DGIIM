/* 
 * File:   matrix.cpp
 * Author: MP-team 
 * @warning To be implemented by students. Follow the instructions given in the headers
 */


#include "Matrix.h"
#include <fstream>
#include <assert.h>
#include <cmath>

using namespace std;

double v_npos = Matrix::npos;
const double c_npos = Matrix::npos;

/**
 * @brief Copies the values in a 2D matrix org with nrows and ncols to an also 2D matrix dest.
 * It is assumed that org and dest have the memory properly allocated 
 * @param dest destination matrix
 * @param org  source matrix
 * @param nrows number of rows
 * @param ncols number of cols
 */
void copy(double **dest, double **org, size_t nrows, size_t ncols) {
    for (int i = 0; i < nrows; i++){
        for (int j = 0; j < ncols; j++){
            dest[i][j] = org[i][j];
        }
    }
}

/** 
 * @brief this method reserve memory to allocate a 2D matrix of size r x c.
 * @param r number of rows
 * @param c number of cols
 * @return the pointer to the memory block containing the data
 */
double ** allocate(size_t r, size_t c) {
    double ** block = new double*[r];
    for(int i = 0; i < r; i++)
        block[i] = new double[c];
    // allocate memory into block
    return block;
}

/**
 * @brief In this method, given an index idx it returns the key in the position i, 
 * such that i is the first position in the index such that idx.at(i).getPos()==p
 * @param idx the input index
 * @param p number of 
 * @return the key for first position i in the index such that idx.at(i).getPos()==p
 */
string labelWithValuePosInIndex(const Index & idx, size_t p) {
    string salida;

    bool enc = false;
    for (int i = 0; i < idx.size() && !enc; i++) {
        if (idx.at(i).getPos() == p) {
            salida = idx.at(i).getKey();
            enc = true;
        }
    }
    return salida;
}

void Matrix::deallocate() {
    if (_data != nullptr){
        for (int i = 0; i < _nrows; i++){
            delete [] _data[i];
        }
    }
    delete [] _data;
    _data = nullptr;
    _nrows = 0;
    _ncols = 0;
}


Matrix::Matrix() {
    _nrows = 0;
    _ncols = 0;
    _data = nullptr;
}

void Matrix::setValues(double valor) {
    for (int i = 0; i < _nrows; i++){
        for (int j = 0; j < _ncols; j++){
            _data[i][j] = valor;
        }
    }
}


Matrix::Matrix(size_t r, size_t c, double vdef) {
    _data = allocate(r, c);
    _nrows = r;
    _ncols = c;
    setValues(vdef);
}

Matrix::Matrix(const Matrix& orig) {
    _data = nullptr;
    deallocate();
    _data = allocate(orig._nrows, orig._ncols);
    _nrows = orig._nrows;
    _ncols = orig._ncols;
    copy(_data, orig._data, _nrows, _ncols);
    _rowLabels = orig._rowLabels;
    _colLabels = orig._colLabels;   
}

Matrix::Matrix(const std::string *rowLabels, size_t nrows, const std::string * colsLabels, size_t ncols, double value) {
    if (nrows < 1 || ncols < 1)
        clear();
    else{
        _data = allocate(nrows, ncols);
        _nrows = nrows;
        _ncols = ncols;
        setValues(value);
        //Matrix(nrows, ncols, value);
        setLabels(_rowLabels, rowLabels, nrows);
        setLabels(_colLabels, colsLabels, ncols);
    }
}


std::string Matrix::labelAtRow(size_t row) const {
    return labelWithValuePosInIndex(_rowLabels, row);
}

std::string Matrix::labelAtCol(size_t col) const {
    return labelWithValuePosInIndex(_colLabels, col);
}

void Matrix::resize(size_t nrows, size_t ncols, double value) {
    _data = nullptr;
    deallocate();
    _data = allocate(nrows, ncols);
    _nrows = nrows;
    _ncols = ncols;
    setValues(value);
}

void Matrix::resize(const std::string * rowLabels, size_t nrows, const std::string * colLabels, size_t ncols, double value) {
    if (nrows <= 0 || ncols <= 0)
        clear();
    else{
        resize(nrows, ncols, value);
        setLabels(_rowLabels, rowLabels, nrows);
        setLabels(_colLabels, colLabels, ncols);
    }
}

void Matrix::clear() {
    deallocate();
   _nrows = 0;
   _ncols = 0;
   _rowLabels.clear();
   _colLabels.clear();
}

Matrix::~Matrix() {
    deallocate();
}

double & Matrix::at(size_t f, size_t c) {
    if (0 <= f && f < _nrows && 0 <= c && c < _ncols)
        return _data[f][c];
    else
        return v_npos;
}

const double & Matrix::at(size_t f, size_t c) const {
    if (0 <= f && f < _nrows && 0 <= c && c < _ncols)
        return _data[f][c];
    else
        return c_npos;
}

double & Matrix::operator()(size_t f, size_t c) {
    return at(f, c);
}

const double & Matrix::operator()(size_t f, size_t c) const {
    return at(f, c);
}

int Matrix::rowIndexOf(const std::string & label) const {
    int lowerbound = _rowLabels.lower_bound(label);
    int upperbound = _rowLabels.upper_bound(label);
    
    if (lowerbound == upperbound) //doesnt exist that row
        return c_npos;
    else
        return _rowLabels.at(lowerbound).getPos();
}

int Matrix::colIndexOf(const std::string & label) const {
    int lowerbound = _colLabels.lower_bound(label);
    int upperbound = _colLabels.upper_bound(label);
    
    if (lowerbound == upperbound) //doesnt exist that column
        return c_npos;
    else
        return _colLabels.at(lowerbound).getPos();
    
//    bool found = false;
//    int col_buscada = v_npos;
//    for(int col=0; col<_nrows && !found; col++){
//        if(labelAtCol(col) == label){
//           found = true; 
//           col_buscada = col;
//        } 
//    }
//    
//    return col_buscada;
}

double & Matrix::at(const std::string & rowLabel, const std::string & colLabel) {
    return at(rowIndexOf(rowLabel), colIndexOf(colLabel));
}

double & Matrix::operator()(const std::string & rowLabel, const std::string & colLabel) {
    return (*this).at(rowLabel, colLabel);
}

const double & Matrix::at(const std::string & rowLabel, const std::string & colLabel)const {
    return at(rowIndexOf(rowLabel), colIndexOf(colLabel));
}

const double & Matrix::operator()(const std::string & rowLabel, const std::string & colLabel)const {
    return (*this).at(rowLabel, colLabel);
}

ostream & operator<<(ostream & flujo, const Matrix& m) {
    flujo << to_string(m.rows()) << " " << to_string(m.columns()) << endl;
    
    for (int row = 0; row < m.rows(); row++)
        flujo << m.labelAtRow(row) << " ";
    flujo << endl;
    
    for (int col = 0; col < m.columns(); col++)
        flujo << m.labelAtCol(col) << " ";
    flujo << endl;
    
    for (int row = 0; row < m.rows(); row++){
        for (int col = 0; col < m.columns(); col++){
            flujo << m.at(row, col) << " ";
        }
        flujo << endl;
    }
    
    return flujo;
}

Matrix & Matrix::operator=(const Matrix& m) {
    if (&m != this){
        _nrows = m._nrows;
        _ncols = m._ncols;
        _rowLabels = m._rowLabels;
        _colLabels = m._colLabels;
        if (_nrows == 0 || _ncols == 0){
            clear();
        }
        else{
            _data = allocate(_nrows, _ncols);
            for (int i = 0; i < _nrows; i++){
                for (int j = 0; j < _ncols; j++){
                    at(i, j) = m._data[i][j];
                }
             }  
        }
    }
    
    return *this;
}

bool Matrix::setLabels(Index & idx, const string * labels, int nlabels){
     idx.clear();
    int lb,ub;
    bool correct = true;
    for (int i=0; i< nlabels && correct; i++){
        lb = idx.lower_bound(labels[i]);
        ub = idx.upper_bound(labels[i]);
        if (lb==ub) { // it is NOT in the set
            idx.add(Pair(labels[i],i));
        } else {
            correct = false;
         }
    }
    if (!correct) idx.clear();
    
    return correct;
 }

int Matrix::getLabels(const Index & idx, string * labels) const {
    if (idx.size() > 0) {
        for (int i = 0; i < idx.size(); i++) {
            labels[i] = idx.at(i).getKey();
        }
    }
    return idx.size();
}

int Matrix::getRowLabels(string * labels) const {
    return getLabels(_rowLabels,labels);
}

int Matrix::getColLabels(string *labels) const {
    return getLabels(_colLabels,labels);
}

size_t Matrix::columns() const {
    return _ncols;
}

size_t Matrix::rows() const {
    return _nrows;
}

//uncomment
void Matrix::save(const string & nf) const{
    ofstream fsal(nf);
    if (fsal.is_open()) {
        fsal << "#matrix "; 
        if (_rowLabels.size()==0)
            fsal << "unlabeled"<< endl;
        else fsal << "labeled" << endl;
        fsal << *this;
        fsal.close();
    } else cerr << "Fail creating " << nf << " file" <<endl;
}

void Matrix::load(const string & nf) {
    ifstream fent(nf);
    string labeled, cad;
    clear();
    if (fent.is_open()) {
         fent >> cad >> labeled;
         fent >> _nrows >> _ncols;
         if (labeled == "labeled"){
            for (int i=0;i<_nrows;i++){
                fent >> cad;
                _rowLabels.add(Pair(cad,i));
            }
             for (int i=0;i<_ncols;i++){
                fent >> cad;
                _colLabels.add(Pair(cad,i));
            }
        }
        _data = allocate(_nrows,_ncols); 
        for (int i = 0; i < _nrows; i++) {
            for (int j = 0; j < _ncols; j++) {
                fent >> _data[i][j];
            }
        }
        fent.close();
    } else cerr << "Fail reading " << nf << " file" <<endl;
}

Matrix & Matrix::operator*=(double val) {
    for (int i = 0; i < _nrows; i++){
        for (int j = 0; j < _ncols; j++){
            at(i, j) *= val;
        }
    }
    return *this;
}

Matrix & Matrix::operator+=(double val) {
    for (int i = 0; i < _nrows; i++){
        for (int j = 0; j < _ncols; j++){
            at(i, j) += val;
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix & m) const {
    string * brands1;
    brands1 = new string [_nrows];
    for (int i = 0; i < _nrows; i++)
        brands1[i] = labelAtRow(i);
    string * brands2;
    brands2 = new string [m.columns()];
    for (int i = 0; i < m.columns(); i++)
        brands2[i] = m.labelAtCol(i);
    
    Matrix matrix(brands1, _nrows, brands2, m._ncols);
    if ( _ncols == m._nrows){
        for (int row = 0; row < _nrows; row++){
            for (int col = 0; col < m._nrows; col++){
                double result = 0;
                for (int k = 0; k < _ncols; k++){
                    result += at(row, k) * m.at(k, col);
                }

                matrix.at(row, col) = result;
            }
        }
    }
    
    brands1 = nullptr;
    delete [] brands1;
    
    brands2 = nullptr;
    delete [] brands2;
    
    return matrix;
}


Matrix Matrix::operator+(double val) const {
    Matrix matrix = *this;
    matrix += val;
    return matrix;
}

Matrix Matrix::operator*(double val) const {
    Matrix matrix = *this;
    matrix *= val;
    return matrix;
}

Matrix operator+(double ival, const Matrix & dch) {
    return dch+ival;
}

Matrix operator*(double ival, const Matrix & dch) {
    return dch*ival;
}

Matrix & Matrix::normalize(){
    for (int i = 0; i < _nrows; i++){
        double result = 0;
        for (int k = 0; k < _ncols; k++)
                result += at(i, k);
        for (int j = 0; j < _ncols; j++){
            if (result != 0)
                at(i, j) /= result;
            else
                at(i, j) = 1.0/_ncols;
        }
    }
    
    return *this;
}
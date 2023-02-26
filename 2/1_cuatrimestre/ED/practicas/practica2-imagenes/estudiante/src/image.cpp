/**
 * @file image.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Image
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <cmath>
#include <image.h>
#include <imageIO.h>


using namespace std;

/********************************
      FUNCIONES PRIVADAS
********************************/
void Image::Allocate(int nrows, int ncols, byte * buffer){
    rows = nrows;
    cols = ncols;

    img = new byte * [rows];

    if (buffer != 0)
        img[0] = buffer;
    else
        img[0] = new byte [rows * cols];

    for (int i=1; i < rows; i++)
        img[i] = img[i-1] + cols;
}

// Función auxiliar para inicializar imágenes con valores por defecto o a partir de un buffer de datos
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

// Función auxiliar para copiar objetos Imagen

void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int k=0; k<rows*cols;k++)
        set_pixel(k,orig.get_pixel(k));
}

// Función auxiliar para destruir objetos Imagen
bool Image::Empty() const{
    return (rows == 0) || (cols == 0);
}

void Image::Destroy(){
    if (!Empty()){
        delete [] img[0];
        delete [] img;
    }
}

LoadResult Image::LoadFromPGM(const char * file_path){
    if (ReadImageKind(file_path) != IMG_PGM)
        return LoadResult::NOT_PGM;

    byte * buffer = ReadPGMImage(file_path, rows, cols);
    if (!buffer)
        return LoadResult::READING_ERROR;

    Initialize(rows, cols, buffer);
    return LoadResult::SUCCESS;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto

Image::Image(){
    Initialize();
}

// Constructores con parámetros
Image::Image (int nrows, int ncols, byte value){
    Initialize(nrows, ncols);
    for (int k=0; k<rows*cols; k++) set_pixel(k,value);
}

bool Image::Load (const char * file_path) {
    Destroy();
    return LoadFromPGM(file_path) == LoadResult::SUCCESS;
}

// Constructor de copias

Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}

// Destructor

Image::~Image(){
    Destroy();
}

// Operador de Asignación

Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}

// Métodos de acceso a los campos de la clase

int Image::get_rows() const {
    return rows;
}

int Image::get_cols() const {
    return cols;
}

int Image::size() const{
    return get_rows()*get_cols();
}

// Métodos básicos de edición de imágenes
void Image::set_pixel (int i, int j, byte value) {
    img[i][j] = value;
}
byte Image::get_pixel (int i, int j) const {
    return img[i][j];
}

// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?
    img[0][k] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)?
    return img[0][k];
}

// Métodos para almacenar y cargar imagenes en disco
bool Image::Save (const char * file_path) const {
    // TODO this makes assumptions about the internal representation
    byte * p = img[0];
    return WritePGMImage(file_path, p, rows, cols);
}

// Método para invertir una imagen
void Image::Invert() {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            set_pixel(i, j, 255 - get_pixel(i, j));
}


// Calcula la media de los pixeles de una imagen entera o de un fragmento de esta
double Image::Mean(int i, int j, int height, int width) const {
    double suma = 0;
    for (int f = i; f < i + height; ++f)
        for (int c = j; c < j + width; ++c)
            suma += img[f][c];

    double media = suma / (height * width); // Media aritmetica
    return media;
}


// Genera un icono como reducción de una imagen
Image Image::Subsample(int factor) const {
    Image icono(rows/factor, cols/factor);

    for (int i = 0; i < icono.rows; ++i){
        for (int j = 0; j < icono.cols; ++j) {

            int valor = 0;
            double media = Mean(i*factor, j*factor, factor, factor);

            // Redondear
            if (media - int(media) >= 0.5)
                valor = int(media) + 1;
            else
                valor = int(media);

            icono.set_pixel(i, j, valor);
        }
    }
    return icono;
}

// Modifica el congtraste de una iamgen
void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2) {
    int total_pixeles = rows * cols;

    double cociente1 = out1*1.0/in1;
    double cociente2 = (out2 - out1)*1.0/ (in2 - in1);
    double cociente3 = (255 - out2)*1.0/ (255 - in2);

    for (int i = 0; i < total_pixeles; ++i) {
        double valor = 0;
        byte pixel = get_pixel(i);
        if (pixel < in1)
            valor = cociente1*pixel;
        if (in1 <= pixel && pixel <= in2)
            valor = out1 + cociente2*(pixel - in1);
        if (pixel > in2)
            valor = out2 + cociente3*(pixel - in2);

        set_pixel(i, round(valor));
    }
}
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startX = ui->frame->x();
    startY = ui->frame->y();
    width = ui->frame->width();
    height = ui->frame->height();
    img = new QImage(width,height,QImage::Format_RGB32);
    img->fill(Qt::black);
    int defaultValue = 0;
    drawColorsR(defaultValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    qApp->quit();
}


void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);

    p.drawImage(ui->frame->frameGeometry(),*img,ui->frame->frameGeometry());
    p.end();
}

void MainWindow::drawColorsR(int &R) {
    KolorRGB c;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            c.R = R;
            c.G = round((double)i/width * 255);
            c.B = round((double)(height-j)/height * 255);
            rysuj_piksel(i,j,c);
        }
    }
    update();
}

void MainWindow::drawColorsG(int &G) {
    KolorRGB c;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            c.R = round((double)i/width * 255);
            c.G = G;
            c.B = round((double)(height-j)/height * 255);
            rysuj_piksel(i,j,c);
        }
    }
    update();
}
void MainWindow::drawColorsB(int &B) {
    KolorRGB c;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            c.R = round((double)i/width * 255);
            c.G = round((double)(height-j)/height * 255);
            c.B = B;
            rysuj_piksel(i,j,c);
        }
    }
    update();
}

void MainWindow::drawHue(int &H) {
    KolorRGB c;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            c = HSVtoRGB(H,(double)(height-j)/height*100,(double)i/width*100);
            rysuj_piksel(i,j,c);
        }
    }
    update();
}
void MainWindow::drawSat(int &S) {
    KolorRGB c;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            c = HSVtoRGB((double)i/width*360,S,(double)j/height*100);
            rysuj_piksel(i,j,c);
        }
    }
    update();
}
void MainWindow::drawV(int &V) {
    KolorRGB c;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            c = HSVtoRGB((double)i/width*360,(double)j/height*100,V);
            rysuj_piksel(i,j,c);
        }
    }
    update();
}

KolorRGB MainWindow::HSVtoRGB(double H, double S, double V) {
    double s = S/100;
    double v = V/100;
    double C = s*v;
    double X = C*(1-abs(fmod(H/60.0, 2)-1));
    double m = v-C;
    double r,g,b;
    if(H >= 0 && H < 60){
        r = C,g = X,b = 0;
    }
    else if(H >= 60 && H < 120){
        r = X,g = C,b = 0;
    }
    else if(H >= 120 && H < 180){
        r = 0,g = C,b = X;
    }
    else if(H >= 180 && H < 240){
        r = 0,g = X,b = C;
    }
    else if(H >= 240 && H < 300){
        r = X,g = 0,b = C;
    }
    else{
        r = C,g = 0,b = X;
    }
    KolorRGB RGB((r+m)*255,(g+m)*255,(b+m)*255);
    return RGB;
}

void MainWindow::rysuj_piksel(int &x, int &y, KolorRGB &color) {
    if (x > img->width() || y > img->height() || x < 0 || y < 0) {
        return;
    } else {
        unsigned char *ptr;
        ptr = img->bits();
        ptr[width*4*y + 4*x] = color.B;
        ptr[width*4*y + 4*x + 1] = color.G;
        ptr[width*4*y + 4*x + 2] = color.R;
    }
}


void MainWindow::on_RSlider_valueChanged(int value)
{
    drawColorsR(value);
}
void MainWindow::on_GSlider_valueChanged(int value)
{
    drawColorsG(value);
}
void MainWindow::on_BSlider_valueChanged(int value)
{
    drawColorsB(value);
}
void MainWindow::on_HSlider_valueChanged(int value)
{
    drawHue(value);
}
void MainWindow::on_SSlider_valueChanged(int value)
{
    drawSat(value);
}
void MainWindow::on_VSlider_valueChanged(int value)
{
    drawV(value);
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <types.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RSlider_valueChanged(int value);
    void on_GSlider_valueChanged(int value);
    void on_BSlider_valueChanged(int value);
    void on_exitButton_clicked();
    void paintEvent(QPaintEvent*);
    void on_HSlider_valueChanged(int value);
    void on_SSlider_valueChanged(int value);
    void on_VSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QImage *img;

    int startX;
    int startY;
    int width;
    int height;

    void drawColorsR(int &R);
    void drawColorsG(int &G);
    void drawColorsB(int &B);
    void drawHue(int &H);
    void drawSat(int &S);
    void drawV(int &V);
    void rysuj_piksel(int &x, int &y, KolorRGB &color);
    KolorRGB HSVtoRGB(double H,double S,double V);
};
#endif // MAINWINDOW_H

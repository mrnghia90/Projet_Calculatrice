#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "crectangle.h"
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QGraphicsView>
#include <iostream>
#include <string.h>


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineEdit *TraceCalcul;
    QLineEdit *CoefA;
    QLineEdit *CoefB;
    void ajouterChiffre(int chiffre) ;
    void operation(char op);
private slots:
    void on_bVider_clicked();
    void on_b0_clicked();
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_b9_clicked();
    void on_bMoinNeg_clicked();
    void on_bPlus_clicked();
    void on_bMoin_clicked();
    void on_bFois_clicked();
    void on_bDivise_clicked();
    void on_bEgale_clicked();
    void on_bVirgule_clicked();
    void on_bViderGraph_clicked();
    void on_bTracer_clicked();
private:
    Ui::MainWindow *ui;
    CRectangle *r;
    void paintEvent(QPaintEvent* e);
    int etat ;
    bool Moin_negative; // true ssi il y a un moins (-) à ajouter
    //(le moins négatif ne s'ajoute que lorsque le caractère suivant est tapé, donc les moins négatifs sont retnus en mémoire)
    bool moins_possible ; // true ssi ajouter un moins (-) ne pose pas de problème de syntaxe
    char operateur;
    double operande1, operande2;
    int etat_graphe;
    double a ,b;

};
#endif // MAINWINDOW_H

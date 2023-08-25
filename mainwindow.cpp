#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    etat = 0 ;
    operande1 = 0 ;
    operande2 = 0 ;
    etat_graphe = 0 ;
    Moin_negative = 0 ;
    moins_possible = 1 ;
    a = 1 ;
    b = 1 ;
}



MainWindow::~MainWindow()
{
    delete ui;
    delete r;
}



void MainWindow::paintEvent(QPaintEvent *e)
{

    QWidget::paintEvent(e);
    QPainter rectangle(this) ;
    rectangle.drawRect(15,15,256,192) ;
    rectangle.setPen( QPen(Qt::black, 1) );

    rectangle.fillRect( 16, 16, 255, 191, QBrush(Qt::white) );

    QPainter Ox(this);
    Ox.drawLine(15, 111,271,111);
    QPainter Oy(this);
    Oy.drawLine(143, 15,143,207);

    if (etat_graphe == 1){
        QPen decoDroit(Qt::red);
        decoDroit.setWidth(2);
        double H = 96.0, L = 128.0, M= 143.0, N = 111.0;
        double EcoordX = 0.0, EcoordY = 0.0, ScoordX = 0.0, ScoordY = 0.0 ;
            // Arrivée
        if(-a*L+b>H){
            // La courbe commence en haut
            EcoordY = N - H ;
            EcoordX = (H-b)/a + M ;
        }
        else{
            if(-a*L+b<-H){
                // La courbe arrive par le bas
                EcoordY = N+H ;
                EcoordX = (-b-H)/a + M ;
            }
            else{
                // La courbe arrive par le bord gauche
                EcoordY = N+a*L - b ;
                EcoordX = M-L ;
            }
        }
        if(a*L+b>H){
            // La courbe part vers le haut
            ScoordY = N - H ;
            ScoordX = (H-b)/a + M ;
        }
        else{
            if(a*L+b<-H){
                // La courbe part vers le bas
                ScoordY = N+H ;
                ScoordX = -(b+H)/a + M ;
            }
            else{
                // La courbe sort par le bord gauche
                ScoordX = L+M;
                ScoordY = N - a*L-b;
            }
        }
        // Sortie
        QPainter droite(this);
        droite.setPen(decoDroit);
        droite.drawLine(EcoordX, EcoordY, ScoordX, ScoordY) ;
    }
}

void MainWindow::on_bVider_clicked()
{
    this->ui->TraceCalcul->clear();
    etat = 0;
    Moin_negative = false;
    moins_possible = 1 ;

}

void MainWindow::on_b0_clicked()
{
    if (this->ui->TraceCalcul->text() != "0"){
        ajouterChiffre(0) ;
    }
}

void MainWindow::on_b1_clicked()
{
    ajouterChiffre(1);
}
/*
void MainWindow::ajouterChiffre(int chiffre)
{
    if (etat== 0){
        // On efface ce qui a été écrit précédemment et on écrit le nouveau chiffre
        this->ui->TraceCalcul->clear();
        // avec un moins si l'utilisateur avait cliqué sur (-)
        if (Moin_negative){
            this->ui->TraceCalcul->setText("-");
            Moin_negative = 0 ;
        }
        this->ui->TraceCalcul->setText(this->ui->TraceCalcul->text() + QString::number(chiffre));
        etat = 1;
    }
    else{
        this->ui->TraceCalcul->setText(this->ui->TraceCalcul->text() + QString::number(chiffre));
    }
    moins_possible = 0 ;
}
*/
void MainWindow::ajouterChiffre(int chiffre)
{
    if (etat== 0){
        // On efface ce qui a été écrit précédemment et on écrit le nouveau chiffre
        this->ui->TraceCalcul->clear();
        etat = 1;
    }
    if (Moin_negative){
        this->ui->TraceCalcul->setText("-");
        Moin_negative = 0 ;
    }
    this->ui->TraceCalcul->setText(this->ui->TraceCalcul->text() + QString::number(chiffre));

    moins_possible = 0 ;
}

void MainWindow::on_b2_clicked()
{
    ajouterChiffre(2) ;
}

void MainWindow::on_b3_clicked()
{
    ajouterChiffre(3) ;
}
void MainWindow::on_b4_clicked()
{
    ajouterChiffre(4) ;
}
void MainWindow::on_b5_clicked()
{
    ajouterChiffre(5) ;
}

void MainWindow::on_b6_clicked()
{
    ajouterChiffre(6) ;
}

void MainWindow::on_b7_clicked()
{
    ajouterChiffre(7) ;
}

void MainWindow::on_b8_clicked()
{
    ajouterChiffre(8) ;
}

void MainWindow::on_b9_clicked()
{
    ajouterChiffre(9) ;
}

void MainWindow::on_bMoinNeg_clicked(){
    if (moins_possible){
        Moin_negative = 1 ;
    }
    moins_possible = 0 ;
}
void MainWindow::operation(char op){
    if (etat == 1){
        operande1 = this->ui->TraceCalcul->text().toDouble();
        this->ui->TraceCalcul->setText("");
        operateur = op;
        etat = 2;
        Moin_negative = 0 ;
        moins_possible = 1 ;
    }
}
void MainWindow::on_bPlus_clicked(){
    operation('+') ;
}

void MainWindow::on_bMoin_clicked(){
    operation('-') ;
}


void MainWindow::on_bFois_clicked(){
    operation('*') ;
}
void MainWindow::on_bDivise_clicked(){
    operation('/') ;
}
void MainWindow::on_bEgale_clicked(){
    string str;
    if (etat == 1){
        operande1 = this->ui->TraceCalcul->text().toDouble();
        this->ui->TraceCalcul->setText(QString::number(operande1)+"="+QString::number(operande1));
    }
    else{
        operande2 = this->ui->TraceCalcul->text().toDouble();
        if (etat == 2){
            switch (operateur){
            case '+':
                this->ui->TraceCalcul->setText(QString::number(operande1)+"+"+QString::number(operande2)+"="+QString::number(operande1 + operande2));
                break;
            case '-':
                this->ui->TraceCalcul->setText(QString::number(operande1)+"-"+QString::number(operande2)+"="+QString::number(operande1 - operande2));
                break;
            case '*':
                this->ui->TraceCalcul->setText(QString::number(operande1)+"*"+QString::number(operande2)+"="+QString::number(operande1 * operande2));
                break;
            case '/':
                if (operande2 == 0){
                    this->ui->TraceCalcul->setText("Diviser par 0 !!!!!");
                }
                else {
                this->ui->TraceCalcul->setText(QString::number(operande1)+"/"+QString::number(operande2)+"="+QString::number(operande1 / operande2));
                }
                break;
            }
        }
    }
    etat = 0 ;
    moins_possible = 1 ;
    Moin_negative = 0 ;
}

void MainWindow::on_bVirgule_clicked(){
    if (etat == 0){
        this->ui->TraceCalcul->setText("");
        etat = 1 ;
    }
    if (Moin_negative){
        this->ui->TraceCalcul->setText("-");
        Moin_negative = 0 ;
    }
    if (!this->ui->TraceCalcul->text().contains(".")){
        this->ui->TraceCalcul->setText(this->ui->TraceCalcul->text() + ".");
    }
}

void MainWindow::on_bViderGraph_clicked(){
    etat_graphe = 0;
    this->ui->CoefA->clear();
    this->ui->CoefB->clear();
    update();
}

void MainWindow::on_bTracer_clicked(){
    etat_graphe = 1;
    a = this->ui->CoefA->text().toDouble();
    b =10* this->ui->CoefB->text().toDouble();
    update();
}




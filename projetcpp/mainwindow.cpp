#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "QMediaPlayer"
#include <QMessageBox>
#include <QApplication>
#include <QCoreApplication>
#include "dialog.h"
#include "dossier.h"
#include <QtPrintSupport>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView->setModel(tmppatient.afficher());
    ui->tableView_2->setModel(tmpdossier.afficher());
    music1 =new QMediaPlaylist();
    music1->addMedia(QUrl("qrc:/music.mp3"));
    music1->setPlaybackMode(QMediaPlaylist::Loop);
    music = new QMediaPlayer();
    music->setPlaylist(music1);
    music->setVolume(1);
    music->play();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete music;
}

void MainWindow::click()
{

    QMediaPlayer * music =new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Click2.mp3"));
    music->play();
}
void MainWindow::ref()
{
    ui->tableView->setModel(tmppatient.afficher());
    ui->tableView_2->setModel(tmpdossier.afficher());
}

void MainWindow::on_pushButton_clicked()
{
    int i=ui->pid->text().toInt();
    QString p=ui->pnom->text();
    QString k=ui->pprenom->text();
    QString l=ui->psexe->currentText();
    float d= ui->ppoids->text().toFloat();
    float e= ui->ptaille1->text().toFloat();
    QString  m=ui->pemail->text();
    QString  r=ui->padresse->text();



    patient c(i,p,k,l,d,e,m,r);


    if ((i!='\0')&&(p!='\0')&&(k!='\0')&&(d!='\0'))
    {

    bool test = c.ajouter();
    if(test)

    {   ref();
        click();
        QMessageBox::information(nullptr,("Ajout patient"),("patient ajouté"));}
else
     {QMessageBox::warning(nullptr,("Ajout patient"),("patient non ajouté"));}
    }

    else QMessageBox::warning(nullptr,("Ajout patient"),("pas de données"));
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString a=ui->tableView->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from patient where ID=:id");
    query.bindValue(":id", a);

    if (query.exec())
    {

        while (query.next()) {
            click();

            ui->pnom_3->setText(query.value(1).toString());
            ui->pprenom_3->setText(query.value(2).toString());
            ui->lineEdit->setText(query.value(0).toString());
            ui->idp->setText(query.value(0).toString());
            ui->sup_id->setText(query.value(0).toString());
            ui->ppoids_3->setText(query.value(4).toString());
            ui->ptaille1_3->setText(query.value(5).toString());
            ui->padresse_3->setText(query.value(6).toString());
            ui->pemail_3->setText(query.value(7).toString());


        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int i=ui->lineEdit->text().toInt();
    QString p=ui->pnom_3->text();
    QString k=ui->pprenom_3->text();
    QString l=ui->psexe_3->currentText();
    float d= ui->ppoids_3->text().toFloat();
    float e= ui->ptaille1_3->text().toFloat();
    QString  m=ui->pemail_3->text();
    QString  r=ui->padresse_3->text();


    patient c(i,p,k,l,d,e,m,r);
    c.modifier();
    bool test=c.modifier();
    if(test)
    {

        ref();
click();
        QMessageBox::information(nullptr, QObject::tr("Modifier un patient"),
                    QObject::tr("chantier modifier modifié.\n"
                                "Cliquez sur Ok pour continuer."), QMessageBox::Ok);
    }
    else

       QMessageBox::critical(nullptr, QObject::tr("Modifier un patient"),
                   QObject::tr("Erreur!\n"
                               "Erreur de modification de le patient.\n Veuillez réessayer."), QMessageBox::Ok);
}

void MainWindow::on_pushButton_3_clicked()
{
    int a=ui->sup_id->text().toInt();
    bool test=tmppatient.supprimer(a);

    if (a!='\0'){
    QMessageBox::StandardButton reponse = QMessageBox::question(this,"suppression","confirmer la suppression",QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {

        if(test)
        {
ref();
click();
            QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                        QObject::tr("patient supprimé.\n"
                                    "Click Ok to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else  return;}
}

void MainWindow::on_pb_ok1_clicked()
{
    if (ui->radioButton_3->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tableView->setModel(tmppatient.cherchernom(type));
        click();
    }

    if (ui->radioButton->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tableView->setModel(tmppatient.chercherpre(type));
        click();
    }

    if (ui->radioButton_2->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tableView->setModel(tmppatient.chercherid(type));
        click();
    }
    if (!(ui->radioButton_3->isChecked())&&!(ui->radioButton_2->isChecked())&&!(ui->radioButton->isChecked()))
           { click();
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ref();
    click();
}

void MainWindow::on_pushButton_5_clicked()
{
    click();
    Dialog d;
    d.exec();

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="Nom")
       {
        if (ui->radioButton_7->isChecked())
        {
            ui->tableView->setModel(tmppatient.trier_nom());
            click();
        }
        if (ui->radioButton_8->isChecked())
        {
            ui->tableView->setModel(tmppatient.trier_nom2());
            click();
        }
       }
    if(arg1=="Prénom")
       {
        if (ui->radioButton_7->isChecked())
        {
            ui->tableView->setModel(tmppatient.trier_pren());
            click();
        }
        if (ui->radioButton_8->isChecked())
        {
            ui->tableView->setModel(tmppatient.trier_pren2());
            click();
        }
       }
    if(arg1=="Poids")
       {
        if (ui->radioButton_7->isChecked())
        {
            ui->tableView->setModel(tmppatient.trier_poids());
            click();
        }
        if (ui->radioButton_8->isChecked())
        {
            ui->tableView->setModel(tmppatient.trier_poids2());
            click();
        }
       }
    if(arg1=="Taille")
       {
        if (ui->radioButton_7->isChecked())
        {
            ui->tableView->setModel(tmppatient.trier_taille());
            click();
        }
        if (ui->radioButton_8->isChecked())
        {
            ui->tableView->setModel(tmppatient.trier_taille2());
            click();
        }
       }
    if (arg1=="Select")
    {click();
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Tu n'as pas choisis   !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    int i=ui->nf->text().toInt();
    int p=ui->idp->text().toInt();
    QDate k=ui->dateEdit->date();
    int l=ui->age->text().toInt();
    QDate d= ui->dateEdit_2->date();
    QString o=ui->note98->toPlainText();
    dossier c(i,p,k,l,d,o);


    if ((i!='\0')&&(p!='\0')&&(o!='\0')&&(l!='\0'))
    {

    bool test = c.ajouter();
    if(test)

    {
ref();
click();
        QMessageBox::information(nullptr,("Ajout dossier"),("dossier ajouté"));}
else
     {QMessageBox::warning(nullptr,("Ajout dossier"),("dossier non ajouté"));}
    }

    else QMessageBox::warning(nullptr,("Ajout dossier"),("pas de données"));
}

void MainWindow::on_pb_ok1_2_clicked()
{
    if (ui->radioButton_4->isChecked())
    {
        QString type= ui->lineEdit_19->text() ;
        ui->tableView_2->setModel(tmpdossier.chercherage(type));
        click();
    }

if (ui->radioButton_6->isChecked())
    {
        QString type= ui->lineEdit_19->text() ;
        ui->tableView_2->setModel(tmpdossier.cherchernote(type));
        click();
    }
    if (!(ui->radioButton_4->isChecked())&&!(ui->radioButton_6->isChecked()))
           { click();
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    int a=ui->sup_id_2->text().toInt();
        bool test=tmpdossier.supprimer(a);

        if (a!='\0'){
        QMessageBox::StandardButton reponse = QMessageBox::question(this,"suppression","confirmer la suppression",QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {

            if(test)
            {
    ref();
    click();
                QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                            QObject::tr("patient supprimé.\n"
                                        "Click Ok to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else  return;}
}

void MainWindow::on_pushButton_7_clicked()
{
    int i=ui->nf_2->text().toInt();
    int p=ui->idp_2->text().toInt();
    QDate k=ui->dateEdit_3->date();
    int l=ui->age_2->text().toInt();
    QDate d= ui->dateEdit_4->date();
    QString o=ui->note_2->toPlainText();
    dossier c(i,p,k,l,d,o);

    c.modifier();
    bool test=c.modifier();
    if(test)
    {

        ref();
click();
        QMessageBox::information(nullptr, QObject::tr("Modifier un dossier"),
                    QObject::tr("dossier modifier modifié.\n"
                                "Cliquez sur Ok pour continuer."), QMessageBox::Ok);
    }
    else

       QMessageBox::critical(nullptr, QObject::tr("Modifier un dossier"),
                   QObject::tr("Erreur!\n"
                               "Erreur de modification de la dossier.\n Veuillez réessayer."), QMessageBox::Ok);
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString a=ui->tableView_2->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from dossier where nf=:nf or idp=:idp");
    query.bindValue(":nf", a);
    query.bindValue(":idp", a);

    if (query.exec())
    {

        while (query.next()) {
            click();

            ui->idp_2->setText(query.value(1).toString());
            ui->dateEdit_3->setDate(query.value(2).toDate());
             ui->dateEdit_4->setDate(query.value(4).toDate());
            ui->sup_id_2->setText(query.value(0).toString());
            ui->nf_2->setText(query.value(0).toString());
            ui->age_2->setText(query.value(3).toString());
            ui->note_2->setText(query.value(5).toString());
            ui->lineEdit_2->setText(query.value(1).toString());



        }
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    ref();
    click();
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    if(arg1=="Noméro de dossier")
       {
        if (ui->radioButton_9->isChecked())
        {
            ui->tableView_2->setModel(tmpdossier.trier_nf());
            click();
        }
        if (ui->radioButton_10->isChecked())
        {
            ui->tableView_2->setModel(tmpdossier.trier_nf2());
            click();
        }
       }
    if(arg1=="Date de consultation")
       {
        if (ui->radioButton_9->isChecked())
        {
            ui->tableView_2->setModel(tmpdossier.trier_datec());
            click();
        }
        if (ui->radioButton_10->isChecked())
        {
            ui->tableView_2->setModel(tmpdossier.trier_datec2());
            click();
        }
       }

    if (arg1=="Select")
    {click();
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Tu n'as pas choisis   !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    click();
    QString num1 = ui->lineEdit_2->text();
        int num = ui->lineEdit_2->text().toInt();

        QSqlQuery query,query1;

        QString idpatient;
        QString ndos="";
        QString nom="";
        QString prn="";
        QDate dateden;
        QString note="";
        QString sexe="";
        QString poids="";
        QString taille="";
        QString adresse="";
        QString email="";
        QString age="";
        QString dateden1;

        if(num1!=""){
        query1.prepare("select * from dossier where idp =:idp");
       query1.bindValue(":idp", num);
        query.prepare("select * from patient where ID =:id");
        query.bindValue(":id", num);
        if (query1.exec()&&query.exec())
        {

            while (query1.next()&&query.next()) {

                 ndos= query1.value(0).toString();
                 idpatient= query.value(0).toString();
                 adresse=query.value(7).toString();
                 email=query.value(6).toString();
                 nom= query.value(1).toString();
                 prn= query.value(2).toString();
                 dateden = query1.value(2).toDate();
                 dateden1=dateden.toString("dd-MM-yyyy");
                 age=query1.value(3).toString();
                 sexe=query.value(3).toString();
                 poids=query.value(4).toString();
                 taille=query.value(5).toString();
                 note=query1.value(5).toString();

             }
        }
              QPrinter printer(QPrinter::HighResolution);
                  printer.setPageSize(QPrinter::A4);

                 QPrintDialog *dialog = new QPrintDialog(&printer);
                  if (dialog->exec() == QDialog::Accepted)
                  {               QPainter painter(&printer);
                                  painter.begin(&printer);
                                  int iYPos = 0;
                                  int iWidth = printer.width();
                                  int iHeight = printer.height();
                                  QPixmap pxPic;
                                  pxPic.load(":/symbole.png","PNG");
                                  QSize s(iWidth/3, iHeight/5);
                                  QPixmap pxScaledPic = pxPic.scaled(s, Qt::KeepAspectRatio, Qt::FastTransformation);
                                  painter.drawPixmap(3700, iYPos, pxScaledPic.width(), pxScaledPic.height(), pxScaledPic);
                                  iYPos += pxScaledPic.height() + 250;
                                  QFont f;
                                      f.setPointSize(20);
                                      f.setBold(true);
                                      painter.setFont(f);
                                   painter.drawText(1800, 500, "Dossier medicale");
                                   f.setPointSize(15);
                                   f.setBold(true);
                                   painter.setFont(f);
                                   painter.drawText(100, 1000, "N° dossier:");
                                   painter.drawText(1500, 1000,ndos);
                                   painter.drawText(100, 1300, "ID de patient:");
                                   painter.drawText(1500, 1300,idpatient);
                                   painter.drawText(100, 1600, "Adresse:");
                                   painter.drawText(1500, 1600,adresse);
                                   painter.drawText(100, 1900, "E-mail:");
                                   painter.drawText(1500, 1900,email);
                                   painter.drawText(100, 2200, "Nom:");
                                   painter.drawText(1500, 2200,nom);
                                   painter.drawText(100, 2500, "Prénom:");
                                   painter.drawText(1500, 2500,prn);
                                   painter.drawText(100, 2800, "Date de naissance:");
                                   painter.drawText(1500, 2800,dateden1);
                                   painter.drawText(100, 3100, "Age:");
                                   painter.drawText(1500, 3100,age);
                                   painter.drawText(100, 3400, "Sexe:");
                                   painter.drawText(1500, 3400,sexe);
                                   painter.drawText(100, 3700, "Poids en Kg:");
                                   painter.drawText(1500, 3700,poids);
                                   painter.drawText(100, 4000, "Taille en métre:");
                                   painter.drawText(1500, 4000,taille);
                                   painter.drawText(100, 4300, "Note:");
                                   painter.drawText(1500, 4300,note);




                                  painter.end();

                  }
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Imprimer dossier"),
                        QObject::tr("Erreur !.\n"
                                    "Veuillez selectionner un id de patient à imprimer .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

#ifndef DOSSIER_H
#define DOSSIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QDateEdit>


class dossier {

    QString note;
    int idp,age,ndos;
    QDate dcc,dnn;

public :
    dossier();
    dossier(int,int,QDate,int,QDate,QString);

    int getnf(){return ndos;}
    int getid(){return idp;}
    QDate getddn(){return dnn;}
    int getage(){return age;}
    QDate getdcc(){return dcc;}
    QString getnote(){return note;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    QSqlQueryModel * combo_box();
    QSqlQueryModel * combo_boxmail();
    bool supprimer(int);
    QSqlQueryModel * chercherage(const QString &);
    QSqlQueryModel * cherchernote(const QString &);
    QSqlQueryModel * trier_nf();
    QSqlQueryModel * trier_nf2();
    QSqlQueryModel * trier_datec();
    QSqlQueryModel * trier_datec2();


};

#endif // DOSSIER_H

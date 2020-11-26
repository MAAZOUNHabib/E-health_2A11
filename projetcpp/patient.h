#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QDateEdit>

class patient {

    QString adresse,nom,prenom,email,sexe;
    int id;
    float taille,poids;

public :
    patient();
    patient(int,QString,QString,QString,float,float,QString,QString);

    int getID(){return id;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getsexe(){return sexe;}
    float getpids(){return poids;}
    float gettaille(){return taille;}
    QString getad(){return adresse;}
    QString getema(){return email;}

     void setID(int a){id=a;}
     void setnom(QString b){nom=b;}
     void setprenom(QString c){prenom=c;}
     void setsexe(QString d){adresse=d;}
     void setpids(float e){sexe=e;}
     void settaille(float d){taille=d;}
     void setad(QString d){adresse=d;}
     void setema(QString d){email=d;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    QSqlQueryModel * combo_box();
    QSqlQueryModel * combo_boxmail();
    bool supprimer(int);
    QSqlQueryModel * cherchernom(const QString &);
    QSqlQueryModel * chercherpre(const QString &);
    QSqlQueryModel * chercherid(const QString &);
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_pren();
    QSqlQueryModel * trier_poids();
    QSqlQueryModel * trier_taille();
    QSqlQueryModel * trier_nom2();
    QSqlQueryModel * trier_pren2();
    QSqlQueryModel * trier_poids2();
    QSqlQueryModel * trier_taille2();
};

#endif // PATIENT_H

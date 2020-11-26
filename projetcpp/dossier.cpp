#include "dossier.h"

dossier::dossier()
{

}
dossier::dossier(int ndos,int idp,QDate dnn,int age,QDate dcc,QString note)
{
    this->ndos=ndos;
    this->idp=idp;
    this->dnn=dnn;
    this->age=age;
    this->dcc=dcc;
    this->note =note ;

}

bool dossier::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(ndos);
    QString res1= QString::number(idp);
    QString res2= QString::number(age);

    query.prepare("INSERT INTO dossier (nf,idp,dn,age,dc,note) VALUES (:nf,:idp,:dn,:age,:dc,:note)");
    query.bindValue(":nf",res);
    query.bindValue(":idp",res1);
    query.bindValue(":dn",dnn);
    query.bindValue(":age",res2);
    query.bindValue(":dc",dcc);
    query.bindValue(":note",note);

    return    query.exec();
}
QSqlQueryModel * dossier::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from dossier ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Noméro de fichier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID de patient"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de consultaion"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Note"));


    return model;
}
bool dossier::modifier()
{

    QSqlQuery query;
    QString res= QString::number(ndos);
    QString res1= QString::number(idp);
    QString res2= QString::number(age);

    query.prepare("UPDATE dossier SET idp =:idp, dn =:dn, age=:age , dc =:dc, note =:note WHERE nf =:nf") ;
    query.bindValue(":nf",res);
    query.bindValue(":idp",res1);
    query.bindValue(":dn",dnn);
    query.bindValue(":age",res2);
    query.bindValue(":dc",dcc);
    query.bindValue(":note",note);

    return    query.exec();
}
bool dossier::supprimer(int a)
{
    QSqlQuery query;
    QString res= QString::number(a);
    query.prepare("Delete from dossier where nf =:nf");
    query.bindValue(":nf", res);
    return query.exec();
}
QSqlQueryModel * dossier::chercherage(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from dossier where age like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Noméro de fichier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID de patient"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de consultaion"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Note"));

    return model;
}

QSqlQueryModel * dossier::cherchernote(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from dossier where note like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Noméro de fichier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID de patient"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de consultaion"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Note"));

    return model;
}
QSqlQueryModel * dossier::trier_nf()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM dossier\
                        ORDER BY nf ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Noméro de fichier"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID de patient"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date de naissance"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de consultaion"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Note"));
      return  model;
}
QSqlQueryModel * dossier::trier_nf2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM dossier\
                        ORDER BY nf DESC");
                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Noméro de fichier"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID de patient"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date de naissance"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de consultaion"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Note"));
      return  model;
}
QSqlQueryModel * dossier::trier_datec()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM dossier\
                        ORDER BY DC ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Noméro de fichier"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID de patient"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date de naissance"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de consultaion"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Note"));
      return  model;
}
QSqlQueryModel * dossier::trier_datec2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM dossier\
                        ORDER BY DC DESC");
                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Noméro de fichier"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID de patient"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date de naissance"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de consultaion"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Note"));
      return  model;
}

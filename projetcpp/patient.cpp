#include "patient.h"

patient::patient()
{

}

patient::patient(int id,QString nom,QString prenom,QString sexe,float poids ,float taille,QString email ,QString adresse)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->taille=taille;
    this->poids =poids ;
    this->email=email;
    this->adresse=adresse;
}

bool patient::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(poids);
    QString res2= QString::number(taille);

    query.prepare("INSERT INTO patient (ID,nom,PRENOM,sexe,taille,poids,email,adresse) VALUES (:id,:nom,:prenom,:sexe,:taille,:poids,:email,:adresse)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);
    query.bindValue(":poids",res1);
    query.bindValue(":taille",res2);
    query.bindValue(":email",email);
    query.bindValue(":adresse",adresse);
    return    query.exec();
}
QSqlQueryModel * patient::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from patient ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
}
bool patient::modifier()
{

    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(poids);
    QString res2= QString::number(taille);
    query.prepare("UPDATE patient SET ID =:id,   nom =:nom, PRENOM =:prenom, poids=:poids , taille =:taille, adresse =:adresse, email =:email WHERE ID =:id") ;
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);
    query.bindValue(":poids",res1);
    query.bindValue(":taille",res2);
    query.bindValue(":email",email);
    query.bindValue(":adresse",adresse);

    return    query.exec();
}
bool patient::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from patient where ID =:id");
    query.bindValue(":id", res);
    return query.exec();
}
QSqlQueryModel * patient::cherchernom(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from patient where nom like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
}
QSqlQueryModel * patient::chercherpre(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from patient where PRENOM like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
}
QSqlQueryModel * patient::chercherid(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from patient where (ID LIKE '"+type+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
}
QSqlQueryModel * patient::combo_boxmail(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select EMAIL from patient");
    return model;
}
QSqlQueryModel * patient::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM patient\
                        ORDER BY nom ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
                      model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
                      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
      return  model;
}
QSqlQueryModel * patient::trier_nom2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM patient\
                        ORDER BY nom DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
                      model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
                      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
      return  model;
}
QSqlQueryModel * patient::trier_pren()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM patient\
                        ORDER BY prenom ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
                      model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
                      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
      return  model;
}
QSqlQueryModel * patient::trier_pren2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM patient\
                        ORDER BY prenom DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
                      model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
                      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
      return  model;
}
QSqlQueryModel * patient::trier_poids()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM patient\
                        ORDER BY poids ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
                      model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
                      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
      return  model;
}
QSqlQueryModel * patient::trier_poids2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM patient\
                        ORDER BY poids DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
                      model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
                      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
      return  model;
}
QSqlQueryModel * patient::trier_taille()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM patient\
                        ORDER BY taille ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
                      model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
                      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
      return  model;
}
QSqlQueryModel * patient::trier_taille2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM patient\
                        ORDER BY taille DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénon"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poids"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Taille"));
                      model->setHeaderData(6, Qt::Horizontal, QObject::tr("E-mail"));
                      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
      return  model;
}

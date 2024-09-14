#include "formateurs.h"

FORMATEURS::FORMATEURS()
{

}

FORMATEURS::FORMATEURS(int id_formateur,QString nom,QString prenom,QString email,QString specialite,QString ntel)
{
    this->id_formateur = id_formateur;
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
    this->specialite = specialite;
    this->ntel = ntel;

}




void setnom(QString);
void setprenom(QString );
void setemail(QString);
void setspecialite(QString );
void setntel(QString );

  int FORMATEURS::getid_formateur(){return id_formateur;}
  QString FORMATEURS::getnom(){return nom;}
  QString FORMATEURS::getprenom(){return prenom;}
  QString FORMATEURS::getemail(){return email;}
  QString FORMATEURS::getspecialite(){return specialite;}
  QString FORMATEURS::getntel(){return ntel;}

  void FORMATEURS::setid_formateur(int id_formateur){this->id_formateur=id_formateur;}
  void FORMATEURS::setnom(QString nom){this->nom=nom;}
  void FORMATEURS::setprenom(QString prenom ){this->prenom=prenom;}
  void FORMATEURS::setemail(QString email){this->email=email;}
  void FORMATEURS::setspecialite(QString specialite ){this->specialite=specialite;}
  void FORMATEURS::setntel(QString ntel){this->ntel=ntel;}



  bool FORMATEURS::ajouter()
  {

      QSqlQuery query;

      query.prepare("INSERT INTO FORMATEURS (id_formateur,nom,prenom,email,specialite,ntel)"
                    "values(:id_formateur,:nom,:prenom,:email,:specialite,:ntel)");
      query.bindValue(":id_formateur",id_formateur);
          query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
           query.bindValue(":email",email);
           query.bindValue(":specialite",specialite);
           query.bindValue(":ntel",ntel);

            return query.exec();

   };



  QSqlQueryModel * FORMATEURS::afficher(){
      QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery("select * from FORMATEURS");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_formateur"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialite"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("ntel"));


      return model;
  }

  bool FORMATEURS::supprimer(int id_formateur)
  {
        QSqlQuery query;
         QString idString=QString::number(id_formateur);
         query.prepare("delete from FORMATEURS where id_formateur=:id_formateur");
                       //bindValue id =>idstring
         query.bindValue(":id_formateur",idString);
                  return query.exec();
   }


  bool FORMATEURS::modifier(int id_formateur)
  {
  QSqlQuery query;

          query.prepare("UPDATE FORMATEURS SET nom=:nom,prenom=:prenom,email=:email,specialite=:specialite,ntel=:ntel where id_formateur=:id_formateur");
          query.bindValue(":id_formateur",id_formateur);
          query.bindValue(":nom",nom);
          query.bindValue(":prenom",prenom);
          query.bindValue(":email",email);
          query.bindValue(":specialite",specialite);
          query.bindValue(":ntel",ntel);



          return    query.exec();
  }


  QSqlQueryModel* FORMATEURS::selectformateurById(int id_formateur)
   {
       QSqlQueryModel* model = new QSqlQueryModel();
       QSqlQuery query;
       query.prepare("SELECT * FROM FORMATEURS WHERE id_formateur = :id_formateur");
       query.bindValue(":id_formateur", id_formateur);
       if(query.exec())
       {
           model->setQuery(query);
           if(model->rowCount() == 1) // Check if exactly one row is returned
           {
               model->setQuery("select * from FORMATEURS");
               model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_formateur"));
               model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
               model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
               model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
               model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialite"));
               model->setHeaderData(5,Qt::Horizontal,QObject::tr("ntel"));
               return model;
           }
           else
           {
               qDebug() << "Error: No row or more than one row returned for id:" << id_formateur;
               delete model;
               return nullptr;
           }
       }
       else
       {
           qDebug() << "Query execution failed.";
           delete model;
           return nullptr;
       }
   }

  bool FORMATEURS::checkIfIdExists(int)
  {
       QSqlQuery query;
       query.prepare("SELECT id_formateur FROM FORMATEURS WHERE id_formateur = :id_formateur");
       query.bindValue(":id_formateur", id_formateur);

       if (query.exec() && query.next()) {

           return true;
       } else {

           return false;
       }
   }

  bool FORMATEURS::rech(QString rch) {
      QSqlQuery query;
      query.prepare("SELECT * FROM FORMATEURS WHERE " + rch);
      return query.exec();
  }

  bool FORMATEURS::tri(QString tr){

      QSqlQuery query;
          query.prepare("SELECT * FROM FORMATEURS "+tr);
          return query.exec() ;

  }

  bool FORMATEURS::idDisponible(int id_formateur) {
       QSqlQuery query;
       query.prepare("SELECT id_formateur FROM FORMATEURS WHERE id_formateur = :id_formateur");
       query.bindValue(":id_formateur", id_formateur);

       if (query.exec() && query.next()) {

           return true;
       } else {

           return false;
       }
   }




#include "formations.h"

FORMATIONS::FORMATIONS()
{

}

FORMATIONS::FORMATIONS(int id_formation,QString titre,QDate datedebut,QDate datefin,QString duree,int nbrplace,QString typeformation,int id_formateur)
{
    this->id_formation = id_formation;
    this->titre = titre;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->duree = duree;
    this->nbrplace = nbrplace;
    this->typeformation = typeformation;
    this->id_formateur = id_formateur;

}





  int FORMATIONS::getid_formation(){return id_formation;}
  QString FORMATIONS::gettitre(){return titre;}
  QDate FORMATIONS::getdatedebut(){return datedebut;}
  QDate FORMATIONS::getdatefin(){return datefin;}
  QString FORMATIONS::getduree(){return duree;}
  int FORMATIONS::getnbrplace(){return nbrplace;}
  QString FORMATIONS::gettypeformation(){return typeformation;}
  int FORMATIONS::getid_formateur(){return id_formateur;}

  void FORMATIONS::setid_formation(int id_formation){this->id_formation = id_formation;}
  void FORMATIONS::settitre(QString titre){this->titre=titre;}
  void FORMATIONS::setdatedebut(QDate datedebut ){this->datedebut=datedebut;}
  void FORMATIONS::setdatefin(QDate datefin){this->datefin=datefin;}
  void FORMATIONS::setduree(QString duree ){this->duree=duree;}
  void FORMATIONS::setnbrplace(int nbrplace){this->nbrplace=nbrplace;}
  void FORMATIONS::settypeformation(QString typeformation){this->typeformation=typeformation;}
  void FORMATIONS::setid_formateur(int id_formateur){this->id_formateur=id_formateur;}



  bool FORMATIONS::ajouter()
  {

      QSqlQuery query;

      query.prepare("INSERT INTO FORMATIONS (id_formation, titre, datedebut, datefin, duree, nbrplace, typeformation, id_formateur)"
                    "values(:id_formation,:titre,:datedebut,:datefin,:duree,:nbrplace,:typeformation,:id_formateur)");
      query.bindValue(":id_formation",id_formation);
          query.bindValue(":titre",titre);
           query.bindValue(":datedebut",datedebut);
           query.bindValue(":datefin",datefin);
           query.bindValue(":duree",duree);
           query.bindValue(":nbrplace",nbrplace);
           query.bindValue(":typeformation",typeformation);
           query.bindValue(":id_formateur",id_formateur);

            return query.exec();

   };



  QSqlQueryModel * FORMATIONS::afficher(){
      QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery("select * from FORMATIONS");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_formation"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("datedebut"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("datefin"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("duree"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("nbrplace"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("typeformation"));
      model->setHeaderData(7,Qt::Horizontal,QObject::tr("id_formateur"));


      return model;
  }

  bool FORMATIONS::supprimer(int id_formation)
  {
        QSqlQuery query;
         QString idString=QString::number(id_formation);
         query.prepare("delete from FORMATIONS where id_formation=:id_formation");
                       //bindValue id =>idstring
         query.bindValue(":id_formation",idString);
                  return query.exec();
   }


  bool FORMATIONS::modifier(int id_formation)
  {
  QSqlQuery query;

          query.prepare("UPDATE FORMATIONS SET titre=:titre,datedebut=:datedebut,datefin=:datefin,duree=:duree,nbrplace=:nbrplace,typeformation=:typeformation,id_formateur=:id_formateur where id_formation=:id_formation");
          query.bindValue(":id_formation",id_formation);
          query.bindValue(":titre",titre);
          query.bindValue(":datedebut",datedebut);
          query.bindValue(":datefin",datefin);
          query.bindValue(":duree",duree);
          query.bindValue(":nbrplace",nbrplace);
          query.bindValue(":typeformation",typeformation);
          query.bindValue(":id_formateur",id_formateur);



          return    query.exec();
  }


  QSqlQueryModel* FORMATIONS::selectformationById(int id_formation)
  {
      QSqlQueryModel* model = new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("SELECT * FROM FORMATIONS WHERE id_formation = :id_formation");
      query.bindValue(":id_formation", id_formation);

      if(query.exec())
      {
          model->setQuery(query);
          if(model->rowCount() == 1) // Check if exactly one row is returned
          {
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_formation"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("datedebut"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("datefin"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("duree"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbrplace"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("typeformation"));
              model->setHeaderData(7, Qt::Horizontal, QObject::tr("id_formateur"));
              return model;
          }
          else
          {
              qDebug() << "Error: No row or more than one row returned for id:" << id_formation;
          }
      }
      else
      {
          qDebug() << "Query execution failed.";
      }

      delete model;
      return nullptr;
  }

  bool FORMATIONS::checkIfIdExists(int)
  {
       QSqlQuery query;
       query.prepare("SELECT id_formation FROM FORMATIONS WHERE id_formation = :id_formation");
       query.bindValue(":id_formation", id_formation);

       if (query.exec() && query.next()) {

           return true;
       } else {

           return false;
       }
   }

  bool FORMATIONS::rech(QString rch) {
      QSqlQuery query;
      query.prepare("SELECT * FROM FORMATIONS WHERE " + rch);
      return query.exec();
  }

  bool FORMATIONS::tri(QString tr){

      QSqlQuery query;
          query.prepare("SELECT * FROM FORMATIONS "+tr);
          return query.exec() ;

  }
  bool FORMATIONS::idDisponible(int id_formation) {
       QSqlQuery query;
       query.prepare("SELECT id_formation FROM FORMATIONS WHERE id_formation = :id_formation");
       query.bindValue(":id_formation", id_formation);

       if (query.exec() && query.next()) {

           return true;
       } else {

           return false;
       }
   }

  //-------------------- checks mail validation done
  bool FORMATIONS::isValidEmail(QString email)
  {
      QRegularExpression regex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");

         // We use QRegularExpressionMatch to test if the email matches the regex pattern
         QRegularExpressionMatch match = regex.match(email);

         // If the match is valid, return true. Otherwise, return false.
         return match.hasMatch();
  }



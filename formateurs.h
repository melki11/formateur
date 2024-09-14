#ifndef FORMATEURS_H
#define FORMATEURS_H


#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QMainWindow>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QSqlQuery>
#include <QDateTime>
#include <QFile>
#include <QDebug>
class FORMATEURS
{
    public:
        FORMATEURS();
        FORMATEURS(int,QString,QString,QString,QString,QString);

//getters
        int getid_formateur();
        QString getnom();
        QString getprenom();
        QString getemail();
        QString getspecialite();
        QString getntel();


        void setid_formateur(int);
        void setnom(QString);
        void setprenom(QString );
        void setemail(QString);
        void setspecialite(QString );
        void setntel(QString );


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int);
        bool checkIfIdExists(int);
        bool rech(QString rch);
        bool tri(QString tr);
        bool idDisponible(int );


        QSqlQueryModel *rechercher(QString);
        QSqlQueryModel *trier(QString);
        QSqlQueryModel* selectformateurById(int id);


private:
    int id_formateur;
    QString nom;
    QString prenom;
    QString email;
    QString specialite;
    QString ntel;


};

#endif // FORMATEURS_H

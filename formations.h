#ifndef FORMATIONS_H
#define FORMATIONS_H


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
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtPrintSupport/QPrinter>
#include <QLineSeries>

//mail
#include <QByteArray>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSslSocket>

#include <QtCore/QTextStream>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <algorithm>
#include <QVariant>
#include <QtSql>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidget>
#include <QHeaderView>
#include <QLineEdit>
#include <QValidator>
#include <QRegExp>
#include <QRegExpValidator>
#include <QStandardItemModel>
#include <QLabel>
class FORMATIONS
{
    public:
        FORMATIONS();
        FORMATIONS(int,QString,QDate,QDate,QString,int,QString,int);

//getters
        int getid_formation();
        QString gettitre();
        QDate getdatedebut();
        QDate getdatefin();
        QString getduree();
        int getnbrplace();
        QString gettypeformation();
        int getid_formateur();


        void setid_formation(int);
        void settitre(QString);
        void setdatedebut(QDate);
        void setdatefin(QDate);
        void setduree(QString );
        void setnbrplace(int);
        void settypeformation(QString );
        void setid_formateur(int);


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int);
        bool checkIfIdExists(int);
        bool rech(QString rch);
        bool tri(QString tr);
        bool idDisponible(int );
        bool isValidEmail(QString email);


        QSqlQueryModel *rechercher(QString);
        QSqlQueryModel *trier(QString);
        QSqlQueryModel* selectformationById(int id_formation);

private:
        int id_formation;
        QString titre;
        QDate datedebut;
        QDate datefin;
        QString duree;
        int nbrplace;
        QString typeformation;
        int id_formateur;



};
#endif // FORMATIONS_H

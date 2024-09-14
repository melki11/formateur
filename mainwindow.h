#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "formateurs.h"
#include "formations.h"
#include "NotificationLayout.h"
#include "smtp.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_tableView_formateurs_clicked(const QModelIndex &index);

    void on_tableView_formations_clicked(const QModelIndex &index);

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_modifier_clicked();

    void on_statistique_clicked();

    void on_statistique_2_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_recherche_2_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_refresh_2_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_tri_2_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_pdf_2_clicked();

    void on_qrcodegen_clicked();
    void on_pushButton_success_clicked();
    void on_pushButtonModifier_success_clicked();
    void on_pushButtonSupprimer_success_clicked();


    void on_pushButton_historique_clicked();

    void on_pushButton_envoyer_clicked();

private:
    Ui::MainWindow *ui;
    FORMATEURS F;
    FORMATIONS F1;
    NotificationLayout notificationLayout;
};

#endif // MAINWINDOW_H

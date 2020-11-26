#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "patient.h"
#include <QMainWindow>
#include "dossier.h"
#include "QMediaPlayer"
#include "QMediaPlaylist"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void click();
    void ref();


private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pb_ok1_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pb_ok1_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    patient tmppatient;
    dossier tmpdossier;
    QMediaPlaylist* music1;
    QMediaPlayer* music;
};
#endif // MAINWINDOW_H

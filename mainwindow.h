#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addBtn_clicked();
    void on_checkBox3D_stateChanged(int arg1);
    void on_subBtn_clicked();
    void on_scalarMultCheckBox_checkStateChanged(const Qt::CheckState &arg1);
    void on_multBtn_clicked();
    void on_dotBtn_clicked();
    void on_angleBtn_clicked();
    void on_magBtn_clicked();

    void on_crossBtn_clicked();

    void on_magCheckBox_stateChanged(int arg1);

    void on_pltBtn_clicked();

private:
    Ui::MainWindow *ui;
    void setValidators();
    std::pair<std::variant<Vector2D,Vector3D>,std::variant<Vector2D,Vector3D>> readVectors();
};
#endif // MAINWINDOW_H

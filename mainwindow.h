#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

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

  void on_actionExit_triggered();

  void on_actionNew_triggered();

  void on_actionCut_triggered();

  void on_actionCopy_triggered();

  void on_actionPaste_triggered();

  void on_actionSelect_All_triggered();

  void on_actionUndo_triggered();

  void on_actionRedo_triggered();

  void on_actionAbout_triggered();

  void on_actionOpen_triggered();

  void on_actionSave_triggered();

  void on_actionSave_As_triggered();

  void on_actionFaceBook_triggered();

  void on_actionSelect_Font_triggered();

  void on_actionVisit_Developer_s_Site_triggered();

  void on_actionManual_triggered();

private:
  Ui::MainWindow *ui;
  QString currentFile;
};

#endif // MAINWINDOW_H

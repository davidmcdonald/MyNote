#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutmynote.h"
#include <QStatusBar>
#include <QDesktopServices>
#include <QUrl>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  //set mainTextEdit widget to be empty upon startup
  ui->mainTextEdit->setText("");

  MainWindow::statusBar()->showMessage("Ready...");

  //set mainTextEdit to use the whole area of the central widget
  this->setCentralWidget(ui->mainTextEdit);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    // Close the application when done using it
    this->close();
}

void MainWindow::on_actionNew_triggered()
{
    // Clear the text area to start a new note
    ui->mainTextEdit->clear();
}

void MainWindow::on_actionCut_triggered()
{
    // Cust selected text from text view
    ui->mainTextEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    // Copy selected text from text view
    ui->mainTextEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    // Paste text to text view
    ui->mainTextEdit->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    // Select all highlighted text into clipboard
    ui->mainTextEdit->selectAll();
}

void MainWindow::on_actionUndo_triggered()
{
    // Undo previous action
    ui->mainTextEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    // Redo function for editor
    ui->mainTextEdit->redo();
}

void MainWindow::on_actionAbout_triggered()
{
    //Opens the About Dialog box for the application
    AboutMyNote aboutNote;
    aboutNote.setModal(true);
    aboutNote.exec();
}

void MainWindow::on_actionOpen_triggered()
{
    // Function to open saved note file
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;
        }
        setWindowTitle(fileName);
        QTextStream in(&file);
        QString text = in.readAll();
        ui->mainTextEdit->setText(text);
        file.close();
}

void MainWindow::on_actionSave_triggered()
{
    // Function to save a file
      QString fileName;
      // If we don't have a filename from before, get one.
      if (currentFile.isEmpty()) {
          fileName = QFileDialog::getSaveFileName(this, "Save");
          currentFile = fileName;
      } else {
          fileName = currentFile;
      }
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
          QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
          return;
      }
      setWindowTitle(fileName);
      QTextStream out(&file);
      QString text = ui->mainTextEdit->toPlainText();
      out << text;
      file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    // Save As function
      QString fileName = QFileDialog::getSaveFileName(this, "Save as");
      QFile file(fileName);

      if (!file.open(QFile::WriteOnly | QFile::Text)) {
          QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
          return;
      }
      currentFile = fileName;
      setWindowTitle(fileName);
      QTextStream out(&file);
      QString text = ui->mainTextEdit->toPlainText();
      out << text;
      file.close();
}

void MainWindow::on_actionFaceBook_triggered()
{
    // Opens default web browser and takes user to authors FaceBook page
    QDesktopServices::openUrl(QUrl("https://www.facebook.com/groups/futuredevsnow/"));
}

void MainWindow::on_actionTwitter_triggered()
{
    // Opens default web browser and takes user to authors twitter page
    //QDesktopServices::openUrl(QUrl("Add Twitter link here"));
}

void MainWindow::on_actionSelect_Font_triggered()
{
    // Select font for text when clicked
      bool fontSelected;
      QFont font = QFontDialog::getFont(&fontSelected, this);
      if (fontSelected)
          ui->mainTextEdit->setFont(font);
}

void MainWindow::on_actionVisit_Developer_s_Site_triggered()
{
    // Go to the developers website
    QDesktopServices::openUrl(QUrl("https://github.com/davidmcdonald/MyNote"));
}

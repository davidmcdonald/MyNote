#include "aboutmynote.h"
#include "ui_aboutmynote.h"
#include <QDesktopServices>
#include <QUrl>

AboutMyNote::AboutMyNote(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AboutMyNote)
{
  ui->setupUi(this);
}

AboutMyNote::~AboutMyNote()
{
  delete ui;
}

void AboutMyNote::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/davidmcdonald/MyNote"));
}

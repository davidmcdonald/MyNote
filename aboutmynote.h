#ifndef ABOUTMYNOTE_H
#define ABOUTMYNOTE_H

#include <QDialog>

namespace Ui {
  class AboutMyNote;
}

class AboutMyNote : public QDialog
{
  Q_OBJECT

public:
  explicit AboutMyNote(QWidget *parent = nullptr);
  ~AboutMyNote();

private:
  Ui::AboutMyNote *ui;
};

#endif // ABOUTMYNOTE_H

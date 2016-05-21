#include <QWidget>
#include <QApplication>
#include <QtWebEngineWidgets>
#include <QVBoxLayout>
#include <QShortcut>
#include <QObject>
#include <QKeySequence>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QWidget window;
  QUrl url;


  QWebEngineView *view = new QWebEngineView();
  window.setWindowFlags( Qt::CustomizeWindowHint );
  window.setWindowTitle("Browser");
  window.showMaximized();

  url = QUrl("http://www.google.com");
  view->load(url);
  view->show();

  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->addWidget(view);
  vbox->setMargin(0);
  window.setLayout(vbox);
  window.show();

  QShortcut *reload = new QShortcut(QKeySequence("Ctrl+k"), view);
  QObject::connect(reload, SIGNAL(activated()), view, SLOT(reload()));

  QShortcut *back = new QShortcut(QKeySequence("Ctrl+h"), view);
  QObject::connect(back, SIGNAL(activated()), view, SLOT(back()));

  QShortcut *min = new QShortcut(QKeySequence("Ctrl+j"), view);
  QObject::connect(min, SIGNAL(activated()), view, SLOT(showMinimized()));

  QShortcut *forward = new QShortcut(QKeySequence("Ctrl+l"), view);
  QObject::connect(forward, SIGNAL(activated()), view, SLOT(forward()));


  //QShortcut *home = new QShortcut(QKeySequence("Ctrl+w"), view);
  //QObject::connect(home, SIGNAL(activated()), view, SLOT(home()));

    //QShortcut *speed_dial1 = new QShortcut(QKeySequence("Ctrl+a"), view);
    //QObject::connect(speed_dial1, SIGNAL(activated()), view, SLOT(load("http://qt-project.org/support/file.html")));




return app.exec();

 }




